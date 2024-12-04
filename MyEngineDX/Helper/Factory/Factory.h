#pragma once

namespace Engine
{
    template <class TYPE>
	class EntityFactory _ABSTRACT
	{
	public:
    protected:
        template<typename... Args>
        TYPE* CreateAndPushWaitQueue(Args&&... args)
        {
            static_assert(std::is_base_of<Factory, T>::value, "Create_Fail");
            T* instance = new T(std::forward<Args>(args)...);
            mCreateQueue.push_back(instance);
            return instance;
        }
        void CreateUpdate();
        void DestroyUpdate();

        TYPE* GetCreation()
        {
            if (mCreateQueue.empty())
            {
                return nullptr;
            }
            else
            {
                TYPE* pEntity = mCreateQueue.front();
                mCreateQueue.pop();
                pEntity->SetActive(TRUE);
                return pEntity;
            }
        }
    protected:
        std::queue<TYPE*> mCreateQueue;
        std::queue<TYPE*> mDestroyQueue;
	};
}


