#ifndef __MERKEL_H__
#	define __MERKEL_H__

#	include <vector>
#	include <random>
#	include <ctime>

/// <summary>
/// Merkel namespace
/// </summary>
namespace Merkel
{
	/// <summary>
	/// Sort using Merkel's approach on "new" technology
	/// </summary>
	/// <returns>Sorted items</returns>
	template <class _T> std::vector<typename _T> sort(std::vector<typename _T> items)
	{
		std::vector<_T> ret;
		size_t index, push_index;
		_T *prev;
		bool is_good;
		srand(static_cast<unsigned int>(time(nullptr)));

		// Check, if anything should have been solved long time ago
		while (items.size() > 0)
		{
			// Randomly pick an item
			index = static_cast<size_t>(rand() % items.size());

			// Decide if this item is relevant for now
			if ((rand() % 88) == 11)
			{
				// Discuss with people who have zero knowledge where to position this item
				// So push it somewhere
				push_index = static_cast<size_t>(rand() % (ret.size() + 1));
				ret.insert(ret.begin() + push_index, items[index]);

				// Review the current state
				prev = nullptr;
				is_good = true;
				for (_T & item : ret)
				{
					if (prev != nullptr)
					{
						if ((*prev) > item)
						{
							// Discuss about it, why it is bad, and remove the change
							is_good = false;
							ret.erase(ret.begin() + push_index);
							break;
						}
					}
					prev = &item;
				}
				if (is_good)
				{
					// Something has been done correctly this time
					items.erase(items.begin() + index);
				}
			}
		}

		// Perfect result
		return ret;
	}
}

#endif
