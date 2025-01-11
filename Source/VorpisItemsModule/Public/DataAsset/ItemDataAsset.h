// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/Texture2D.h"
#include "Engine/StaticMesh.h"
#include "Engine/SkeletalMesh.h"
#include "ItemData/ItemEnums.h"
#include "ItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class VORPISITEMSMODULE_API UItemDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	// basic data
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Basics")
	FName ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Basics")
	FGuid ItemGuid;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Basics")
	UTexture2D* IconTexture;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Basics")
	bool IsStackable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Basics")
	FString ItemDescription;

	// mesh data
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh")
	TArray<UStaticMesh*> BaseMeshes; // either the whole mesh or its the hilt of a weapon
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh")
	TArray<UStaticMesh*> BladeMeshes; // only for weapons
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh")
	TArray<USkeletalMesh*> SkeletalMeshes; // armor or unique items 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh")
	bool UseSkeletalMesh;

	// equipment data
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equip")
	EEquipmentSlot EquipmentSlot;
	
	// socket data
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Socket")
	EEquipSocketOption EquipSocketOption;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Socket")
	EUnequipSocketOption UnequipSocketOption;

	// weildable data
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weildable")
	bool IsWeildable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weildable")
	bool IsTwoHanded;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weildable")
	EWieldableItemType WieldableItemType;

	// damage data
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	TMap<EPhysicalDamageType, int> DamageMap;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	FGuid StatsScalingGuid; // we dont want all the modules to rely on each other

	// food data
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Food")
	bool IsFood;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Food")
	EFoodType FoodType;

	// consumable data
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
	bool IsConsumable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Consumable")
	EConsumableType ConsumableType;

	// wearable data
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wearable")
	bool IsWearable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wearable")
	EEquipmentLayerType EquipmentLayerType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wearable")
	TMap<EPhysicalDamageType, int> ProtectionMap;
};
