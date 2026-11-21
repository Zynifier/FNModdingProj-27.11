// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraModifier.h"
#include "Engine/Scene.h"
#include "WeaponScopeModifier.generated.h"

UCLASS()
class UWeaponScopeModifier : public UCameraModifier
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WeaponScopeModifier")
	FPostProcessSettings ScopeSettings;

};

