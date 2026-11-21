// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraActorInterface.h"
#include "FortCameraBase.generated.h"

class AFortExhibitActor;
class AFortPlayerController;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Rendering"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortCameraBase : public ACameraActor, public IFortCameraActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Camera|Fortnite", meta=(DisplayName="On Activated"))
	void BP_OnActivated(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintImplementableEvent, Category="Camera|Fortnite", meta=(DisplayName="On Deactivated"))
	void BP_OnDeactivated(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Camera|Fortnite")
	void Exhibit(AFortExhibitActor* TargetActor);

	UFUNCTION(BlueprintImplementableEvent, Category="Camera|Fortnite")
	void OnDragBegin();

	UFUNCTION(BlueprintImplementableEvent, Category="Camera|Fortnite")
	void OnDragEnd();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	float MinDistanceToDrag;

protected:
	UPROPERTY(Transient)
	float DefaultFieldOfView;

	UPROPERTY(Transient)
	FRotator DefaultRotation;

	UPROPERTY(Transient)
	FVector DefaultLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCameraBase")
	TObjectPtr<AFortExhibitActor> ExhibitActor;

	UPROPERTY(Transient)
	bool bExhibitActorChanged;

	UPROPERTY(Transient)
	bool CheckForDragBegin;

	UPROPERTY(Transient)
	FVector2D DownDelta;

};

