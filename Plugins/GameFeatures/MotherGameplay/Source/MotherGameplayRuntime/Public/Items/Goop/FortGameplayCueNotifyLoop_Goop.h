// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotifyLoop_Goop.generated.h"

class UAudioComponent;

USTRUCT()
struct FGoopAudioMapRangeClamped
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="GoopAudioMapRangeClamped")
	FVector2D InRange;

	UPROPERTY(EditDefaultsOnly, Category="GoopAudioMapRangeClamped")
	FVector2D OutRange;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"))
class AFortGameplayCueNotifyLoop_Goop : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FName SpeedParamName;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FName IsFallingParamName;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FGoopAudioMapRangeClamped SpeedMapRangeClamped;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	float InterpSpeed;

	UPROPERTY(BlueprintReadWrite, Export, Category="Audio", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> LoopingAudioComponent;

};

