// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "FortAbilityTask_WaitForCustomCharacterParts.generated.h"

class AFortPlayerPawn;
class UCustomCharacterPart;
class UFortAbilityTask_WaitForCustomCharacterParts;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReady);

UCLASS()
class UFortAbilityTask_WaitForCustomCharacterParts : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnFinishedCharacterCustomizationCallback(AFortPlayerPawn* InPawn);

	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="TRUE", DefaultToSelf="OwningAbility", DisplayName="Wait For Custom Character Parts Ready", HidePin="OwningAbility"))
	static UFortAbilityTask_WaitForCustomCharacterParts* WaitForCustomCharacterPartsReady(UGameplayAbility* OwningAbility, TArray<TSoftObjectPtr<UCustomCharacterPart>> CustomCharacterParts);

	UPROPERTY(BlueprintAssignable)
	FOnReady OnReady;

	UPROPERTY()
	TArray<TSoftObjectPtr<UCustomCharacterPart>> CustomCharacterPartsToWaitFor;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> FortPlayerPawn;

};

