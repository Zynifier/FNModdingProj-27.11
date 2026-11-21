// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "Athena/Tutorial/FortAthenaTutorialTargetInfo.h"
#include "FortAthenaTutorial_Shoot.generated.h"

class AActor;
class ABuildingProp;
class UUserWidget;

USTRUCT(BlueprintType)
struct FFortAthenaTutorial_ShootTargetInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaTutorial_ShootTargetInfo")
	TObjectPtr<AActor> ShootTargetMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaTutorial_ShootTargetInfo")
	TObjectPtr<ABuildingProp> ShootTarget;

};

UCLASS()
class AFortAthenaTutorial_Shoot : public AFortAthenaTutorialBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Shoot Tutorial Actors")
	TArray<FFortAthenaTutorial_TargetInfo> FirstShootTargets;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Shoot Tutorial Actors")
	TObjectPtr<AActor> ShootCameraPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Shoot Tutorial Screens")
	TSubclassOf<UUserWidget> TargetCounterScreen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Shoot Tutorial Config")
	int32 AmmoCountToTriggerReload;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Shoot Tutorial Config")
	float ShootMarkerAppearDelay;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Shooting Targets")
	void OnShootingTargetsActivated();

private:
	UFUNCTION()
	void OnTargetDestroyed(int32 TargetIndex);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera Movement", meta=(AllowPrivateAccess="TRUE"))
	float CameraInSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera Movement", meta=(AllowPrivateAccess="TRUE"))
	float CameraInDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera Movement", meta=(AllowPrivateAccess="TRUE"))
	float CameraWaitTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera Movement", meta=(AllowPrivateAccess="TRUE"))
	float CameraOutSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera Movement", meta=(AllowPrivateAccess="TRUE"))
	float CameraOutDuration;

};

