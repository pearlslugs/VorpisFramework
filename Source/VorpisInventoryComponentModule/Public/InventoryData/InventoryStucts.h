#pragma once

#include "InventoryEnums.h"
#include "ItemData/ItemStructs.h"
#include "InventoryStucts.generated.h"

USTRUCT(BlueprintType)
struct FItemInventoryStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FItemData ItemData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	EInventoryType InventoryType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int ItemCount;
};

USTRUCT(BlueprintType)
struct FInventorySpaceStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int MaxWidth; // max width of inventory
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int MaxHeight; // max height of inventory
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int Depth; // How many layers deep the inventory is

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int MaximumSpace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int CurrentRemainingSpace;

	void SetMaxSpace() { MaximumSpace = MaxWidth * MaxHeight * Depth; }

	EItemRejectionReason AddItemsToInventory(int ItemHeight, int ItemWidth)
	{
		if (ItemHeight > MaxHeight)
		{
			return EItemRejectionReason::EIRR_TooMuchHeight;
		}
		if (ItemWidth > MaxWidth)
		{
			return EItemRejectionReason::EIRR_TooMuchWidth;
		}
		if (CurrentRemainingSpace < ItemHeight * ItemWidth)
		{
			return EItemRejectionReason::EIRR_NotEnoughSpace;
		}
		if (ItemHeight == 0 || ItemWidth == 0)
		{
			return EItemRejectionReason::EIRR_InvalidItem;
		}
		CurrentRemainingSpace -= ItemHeight * ItemWidth;
		return EItemRejectionReason::EIRR_None;
	}

	void RemoveItemsFromInventory(int ItemHeight, int ItemWidth)
	{
		CurrentRemainingSpace += ItemHeight * ItemWidth;
		if (CurrentRemainingSpace > MaximumSpace)
		{
			// send funny toast error
		}
	}

	void ResetInventorySpace()
	{
		CurrentRemainingSpace = MaximumSpace;
	}
};

USTRUCT(BlueprintType)
struct FInventorySaveStruct
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TMap<FGuid, FItemInventoryStruct> InventoryMap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FGuid InventoryGuid;
};