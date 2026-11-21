// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotifyAthena_FallDamageImmunity.generated.h"

class AFortPlayerPawn;
class UFortLayeredAudioComponent;
class USoundBase;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"))
class AFortGameplayCueNotifyAthena_FallDamageImmunity : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Export, Category="FortGameplayCueNotifyAthena_FallDamageImmunity", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> FortLayeredAudioComponent;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyAthena_FallDamageImmunity")
	FName LayeredAudioVelocityName;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyAthena_FallDamageImmunity")
	FVector2D ZVelocityInput;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyAthena_FallDamageImmunity")
	FVector2D ZVelocityOutput;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyAthena_FallDamageImmunity")
	float LayeredAudioFadeInDuration;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyAthena_FallDamageImmunity")
	float LayeredAudioFadeOutDuration;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyAthena_FallDamageImmunity")
	TObjectPtr<USoundBase> RemovalSound;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> TargetPlayerPawn;

};

