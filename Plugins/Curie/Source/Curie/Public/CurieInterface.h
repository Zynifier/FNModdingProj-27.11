// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CurieInteractParams.h"
#include "CurieMinimalTypes.h"
#include "CurieInterface.generated.h"

UINTERFACE()
class CURIE_API UCurieInterface : public UInterface
{
	GENERATED_BODY()
};

class CURIE_API ICurieInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Curie", meta=(DisplayName="OnCurieContainerAcquired"))
	void OnCurieContainerAcquired_BP(const FCurieContainerHandle CurieContainerHandle);

	UFUNCTION(BlueprintImplementableEvent, Category="Curie", meta=(DisplayName="OnCurieContainerReleased"))
	void OnCurieContainerReleased_BP(const FCurieContainerHandle CurieContainerHandle);

	UFUNCTION(BlueprintImplementableEvent, Category="Curie", meta=(DisplayName="OnCurieContainerReparented"))
	void OnCurieContainerReparented_BP(const FCurieContainerHandle CurieContainerHandle);

	UFUNCTION(BlueprintImplementableEvent, Category="Curie", meta=(DisplayName="OnCurieElementAttached"))
	void OnCurieElementAttached_BP(const FCurieContainerHandle CurieContainerHandle, const FGameplayTag ElementTag);

	UFUNCTION(BlueprintImplementableEvent, Category="Curie", meta=(DisplayName="OnCurieElementDetached"))
	void OnCurieElementDetached_BP(const FCurieContainerHandle CurieContainerHandle, const FGameplayTag ElementTag);

	UFUNCTION(BlueprintImplementableEvent, Category="Curie", meta=(DisplayName="OnCurieElementInteract"))
	void OnCurieElementInteract_BP(const FCurieContainerHandle CurieContainerHandle, const FGameplayTag ElementTag, const FCurieInteractParamsHandle& InteractParamsHandle);

	UFUNCTION(BlueprintImplementableEvent, Category="Curie", meta=(DisplayName="OnCurieElementInteractBegun"))
	void OnCurieElementInteractBegun_BP(const FCurieContainerHandle CurieContainerHandle, const FGameplayTag ElementTag, const FCurieInteractParamsHandle& InteractParamsHandle);

	UFUNCTION(BlueprintImplementableEvent, Category="Curie", meta=(DisplayName="OnCurieElementInteractEnded"))
	void OnCurieElementInteractEnded_BP(const FCurieContainerHandle CurieContainerHandle, const FGameplayTag ElementTag, const FCurieInteractParamsHandle& InteractParamsHandle);

	UFUNCTION(BlueprintImplementableEvent, Category="Curie", meta=(DisplayName="OnCurieStateAttached"))
	void OnCurieStateAttached_BP(const FCurieContainerHandle CurieContainerHandle, const FGameplayTag StateTag);

	UFUNCTION(BlueprintImplementableEvent, Category="Curie", meta=(DisplayName="OnCurieStateDetached"))
	void OnCurieStateDetached_BP(const FCurieContainerHandle CurieContainerHandle, const FGameplayTag StateTag);

};

