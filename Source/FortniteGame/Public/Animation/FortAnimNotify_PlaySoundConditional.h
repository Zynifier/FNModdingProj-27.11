// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify_PlaySound.h"
#include "FortAnimNotify_PlaySoundConditional.generated.h"

class UAnimSequenceBase;
class USkeletalMeshComponent;

UCLASS(HideCategories=("Object", "Object", "Object"), meta=(DisplayName="Play Sound Conditional"))
class UFortAnimNotify_PlaySoundConditional : public UAnimNotify_PlaySound
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	bool ShouldTriggerAnimNotify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) const;

};

