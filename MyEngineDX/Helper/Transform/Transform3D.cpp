#include "pch.h"
#include "Transform3D.h"

Transform3D::Transform3D(Transform3D* _parent)
	: mParent(_parent)
	, mChildren()
	, mPostion(), mRotation(), mScale()
	, mLocalMatrix(), mWorldMatrix()
{
}

Transform3D::~Transform3D()
{
	for (auto& child : mChildren)
	{
		child->mParent = nullptr;
	}
	// ��ü�� ������ �� Ŭ������ �����ϴ� Ŭ������ ���ҷ� ����
}

void Transform3D::CalculateMatrix()
{
	Matrix tr = DirectX::XMMatrixTranslation(mPostion.x, mPostion.y, mPostion.z);
	Matrix ro = DirectX::XMMatrixRotationX(mRotation.x)
		* DirectX::XMMatrixRotationY(mRotation.y)
		* DirectX::XMMatrixRotationZ(mRotation.z);
	Matrix sc = DirectX::XMMatrixScaling(mScale.x, mScale.y, mScale.z);

	mLocalMatrix = sc * ro * tr;

	// �������� ���ϱ�
	m_up = Vector3::TransformNormal(Vector3::Up, ro);
	m_forward = Vector3::TransformNormal(Vector3::Forward, ro);
	m_right = Vector3::TransformNormal(Vector3::Right, ro);

	if (mParent)
	{
		mWorldMatrix = mLocalMatrix * mParent->mWorldMatrix;
	}
	else
	{
		mWorldMatrix = mLocalMatrix;
	}

	for (auto child : mChildren)
	{
		child->CalculateMatrix();
	}
}

void Transform3D::SetParent(Transform3D* _parent)
{
	// �θ� �̹� ������ �θ��� �ڽĿ��� �ڽ��� ����
	if (nullptr != mParent)
	{
		auto find = mParent->mChildren.find(this);
		if (find != mParent->mChildren.end()) {
			mParent->mChildren.erase(find);
		}
	}

	// ���ο� �θ� ������ �ڽ� ��Ͽ� �߰�
	if (nullptr != _parent)
	{
		_parent->mChildren.insert(this);
	}

	// �θ� ����
	mParent = _parent;
}
