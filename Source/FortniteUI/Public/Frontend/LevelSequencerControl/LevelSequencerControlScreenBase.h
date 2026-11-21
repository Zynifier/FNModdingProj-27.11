// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "LevelSequencerControlScreenBase.generated.h"

class ALevelSequenceActor;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortLevelSequencerControlScreenBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortLevelSequencerControlScreenBase")
	FName DefaultLevelSequencerTag;

	UPROPERTY(Transient)
	TObjectPtr<ALevelSequenceActor> AssociatedLevelSequenceActor;

};

