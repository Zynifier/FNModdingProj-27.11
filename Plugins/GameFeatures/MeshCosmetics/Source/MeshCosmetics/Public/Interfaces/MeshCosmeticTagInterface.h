// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MeshCosmeticTagInterface.generated.h"

UINTERFACE()
class UMeshCosmeticTagInterface : public UInterface
{
	GENERATED_BODY()
};

class IMeshCosmeticTagInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="MeshCosmeticTag", meta=(DisplayName="OnPostCustomizationAnimGameplayTags"))
	void OnPostCustomizationAnimGameplayTags_BP(const FGameplayTagContainer& GameplayTags);

};

