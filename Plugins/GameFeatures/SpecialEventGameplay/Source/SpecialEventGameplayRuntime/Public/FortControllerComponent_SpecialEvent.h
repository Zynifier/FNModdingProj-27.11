// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_SpecialEvent.generated.h"

class AFortAthenaMutator_SpecialEvent;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_SpecialEvent : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void SendSpecialClientEvent(const FGameplayTag EventTag, const int32 Count);

protected:
	UFUNCTION(Server, Reliable)
	void ServerHandleSpecialClientEvent(const FGameplayTag& EventTag, const int32 Count);

	UPROPERTY(Config)
	bool bForceBuildModeInputComponentToNotConsumeInputs;

	UPROPERTY()
	TWeakObjectPtr<AFortAthenaMutator_SpecialEvent> SpecialEventMutator;

};

