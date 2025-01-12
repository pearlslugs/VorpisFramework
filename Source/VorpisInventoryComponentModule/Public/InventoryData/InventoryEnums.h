#pragma once

#include "InventoryEnums.generated.h"

UENUM(BlueprintType)
enum class EInventoryType : uint8
{
	ITT_General UMETA(DisplayName = "General"),
	ITT_Equipped UMETA(DisplayName = "Equipped"),
	ITT_Quickslots UMETA(DisplayName = "Quickslots"),
};

UENUM(BlueprintType)
enum class EItemRejectionReason : uint8
{
	EIRR_TooMuchHeight UMETA(DisplayName = "Too Much Height"),
	EIRR_TooMuchWidth UMETA(DisplayName = "Too Much Width"),
	EIRR_NotEnoughSpace UMETA(DisplayName = "Not Enough Space"),
	EIRR_InvalidItem UMETA(DisplayName = "Invalid Item"),
	EIRR_None UMETA(DisplayName = "None")
};