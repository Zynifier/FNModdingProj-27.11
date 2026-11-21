// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotifyAthena_AIFleeState.generated.h"

class UStaticMeshComponent;

UCLASS(HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"))
class AFortGameplayCueNotifyAthena_AIFleeState : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void FleeStateTagUpdateCallback(const FGameplayTag Tag, int32 NewCount);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortGameplayCueNotifyAthena_AIFleeState", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> SpriteMeshComponent;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyAthena_AIFleeState")
	FName SpriteMeshAttachSocketName;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyAthena_AIFleeState")
	FTransform SpriteMeshTransform;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyAthena_AIFleeState")
	FGameplayTag FleeStateTag;

};

