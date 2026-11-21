// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MeleeBlockingInterface.generated.h"

UINTERFACE(BlueprintType, Blueprintable)
class UMeleeBlockingInterface : public UInterface
{
	GENERATED_BODY()
};

class IMeleeBlockingInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Blocking")
	void AddTagsToBlockWithMelee(const FGameplayTagContainer& GameplayTagsToBlock);

	UFUNCTION(BlueprintNativeEvent, Category="Blocking")
	FGameplayTagContainer GetTagsToBlockWithMelee() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Blocking")
	void RemoveTagsToBlockWithMelee(const FGameplayTagContainer& GameplayTagsToBlock);

};

