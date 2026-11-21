// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FrontEnd/FrontEndTypes.h"
#include "FortUICameraManagerComponent.generated.h"

class AActor;
class AFortCameraBase;
class IFortUICameraFrameInterface;
class IFortUICameraFrameTargetInterface;
class UFortUICameraManagerComponent;
enum class EFrontEndCamera : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFortUICameraManagerComponent_OnUIViewTargetChanged, UFortUICameraManagerComponent*, UICameraManagerComponent, AActor*, OldUIViewTarget, AActor*, NewUIViewTarget);

USTRUCT(BlueprintType)
struct FCameraPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraPair")
	EFrontEndCamera Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraPair")
	TObjectPtr<AFortCameraBase> Camera;

};

UCLASS(Transient, MinimalAPI)
class UFortUICameraManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Camera|Fortnite")
	EFrontEndCamera GetCamera() const;

	UFUNCTION(BlueprintPure, Category="Camera|Fortnite")
	AFortCameraBase* GetCameraActor() const;

	UFUNCTION(BlueprintPure, Category="Camera|Fortnite")
	float GetZoomLevel() const;

	UFUNCTION(BlueprintCallable, Category="Camera|Fortnite", meta=(CPP_Default_TransitionParams="()"))
	void SetCamera(EFrontEndCamera NewCamera, FViewTargetTransitionParams TransitionParams);

	UFUNCTION(BlueprintCallable, Category="Camera|Fortnite")
	void SetCameraFrame(const TScriptInterface<IFortUICameraFrameInterface> NewFrame);

	UFUNCTION(BlueprintCallable, Category="Camera|Fortnite")
	void SetCustomCameraRotationOffset(const FRotator Offset);

	UFUNCTION(BlueprintCallable, Category="Camera|Fortnite")
	void SetFrameTarget(const TScriptInterface<IFortUICameraFrameTargetInterface>& FrameTarget);

	UFUNCTION(BlueprintCallable, Category="Camera|Fortnite")
	void SetZoomLevel(const float ZoomLevel);

protected:
	UFUNCTION()
	void HandleCameraFrameTargetSettingsChanged(TScriptInterface<IFortUICameraFrameTargetInterface> FrameTarget);

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> ViewTarget;

	UPROPERTY(Transient)
	bool bUpdatingViewTarget;

	UPROPERTY(Transient)
	EFrontEndCamera CurrentCamera;

	UPROPERTY(Transient)
	TMap<EFrontEndCamera, TObjectPtr<AFortCameraBase>> CameraMapping;

};

