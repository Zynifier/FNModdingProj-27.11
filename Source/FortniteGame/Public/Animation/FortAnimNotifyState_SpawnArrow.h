// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimNotifyState_SpawnProp.h"
#include "FortAnimNotifyState_SpawnArrow.generated.h"

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_SpawnArrow : public UFortAnimNotifyState_SpawnProp
{
	GENERATED_BODY()

protected:
	virtual void GetSkeletalMeshPropOverride(AFortPawn* FortPawn, USkeletalMesh*& InOutSkeletalMeshProp, UAnimationAsset*& InOutSkeletalMeshPropAnimation) override;

};

