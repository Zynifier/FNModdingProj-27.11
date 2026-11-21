// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify_PlayParticleEffect.h"
#include "FortAnimNotify_PlayParticleConditional.generated.h"

class UAnimSequenceBase;
class USkeletalMeshComponent;

UCLASS(HideCategories=("Object", "Object", "Object"), meta=(DisplayName="Play Particle Conditional"))
class UFortAnimNotify_PlayParticleConditional : public UAnimNotify_PlayParticleEffect
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	bool ShouldTriggerAnimNotify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) const;

};

