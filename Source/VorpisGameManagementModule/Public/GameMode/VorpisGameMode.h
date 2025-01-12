// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VorpisGameMode.generated.h"

/**
 * 
 */
UCLASS()
class VORPISGAMEMANAGEMENTMODULE_API AVorpisGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	FString SlotName = "CHARACTER_Doug";
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void SetSelectedGameSlotName(FString NewSelectedGameSlotName) { SlotName = NewSelectedGameSlotName; };
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	FString GetSelectedGameSlotName() { return SlotName; };
	
};
