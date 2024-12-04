#include "pch.h"
#include "Factory.h"

namespace Engine
{
	void EntityFactory::CreateUpdate()
	{
		while (!mCreateQueue.empty())
		{
			mCreateQueue.front()->SetActive(true);
			mCreateQueue.pop();
		}
	}
	void EntityFactory::DestroyUpdate()
	{
		while (!mDestroyQueue.empty())
		{
			SAFE_DELETE(mDestroyQueue.front());
			mDestroyQueue.pop();
		}
	}
}