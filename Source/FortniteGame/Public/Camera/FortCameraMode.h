// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "UObject/NoExportTypes.h"
#include "FortCameraMode.generated.h"

class AFortPlayerCameraBase;

UENUM()
enum class EBlendState : uint8
{
	Out = 0,
	BlendingIn = 1,
	In = 2,
	BlendingOut = 3,
};

USTRUCT()
struct FBlendStateData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortTViewTarget : public FTViewTarget
{
	GENERATED_BODY()

};

UCLASS(Abstract, MinimalAPI)
class UFortCameraMode : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerCameraBase> PlayerCamera;

	UPROPERTY(Transient)
	FBlendStateData BlendStateData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Transition", meta=(DisplayName="Transition In Time"))
	float TransitionTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Transition")
	float TransitionOutTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Transition")
	bool bOverrideTransitionOutTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Transition")
	FViewTargetTransitionParams TransitionParams;

protected:
	UPROPERTY(Transient)
	uint8 bResetInterpolation : 1;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="FortCameraMode")
	uint8 bIsUsingConstantFOV : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode")
	uint8 bShouldAllowBlendingWhenActive : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode")
	uint8 bShouldAllowBlendingWhenInactive : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode")
	uint8 bShouldPassViewTargetCheckOnTransition : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode")
	uint8 bShouldClearWeaponRelativeTransform : 1;

};

