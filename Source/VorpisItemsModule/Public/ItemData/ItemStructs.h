#pragma once

#include "ItemEnums.h"
#include "DataAsset/ItemDataAsset.h"
#include "ItemStructs.generated.h"

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()
public:
	// basic data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basics")
	FName ItemName; // quality + material + name, so like "exeptional bronze sword"
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basics")
	FGuid ItemGuid; // how we sort it in  inventory
	
	// damage data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	TMap<EPhysicalDamageType, int> AdjustedDamageMap; // apply scaling and quality to base damage
	
	// other data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Other")
	int Condition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Other")
	EItemQuality ItemQuality;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Material")
	EMaterialType MaterialType;

	// mesh data
	// when its created, we pick a mesh index from the arrays
	// this class is saved, so when its reinitialized, we can get the same mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	int BaseMeshIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	int BladeMeshIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	int SkeletalMeshIndex;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	UItemDataAsset* ItemAsset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GeneralItem")
	FGuid InitialItemGuid; // for look up i guess


};