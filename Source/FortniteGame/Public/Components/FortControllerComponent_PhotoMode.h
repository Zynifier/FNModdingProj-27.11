// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_PhotoMode.generated.h"

class AFortCreativePhotoModeCamera;
class UCameraModifier;
class UFortInputMappingContext;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FForcedExitCallback);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHandleInputActionCallback, const FInputActionInstance&, InputAction);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPhotoFinishedRenderingCallback);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPhotoModeStateChangedCallback);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSavedCameraFoundCallback);

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_PhotoMode : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable, BlueprintCallable)
	void ClientAcceptPhoto() const;

	UFUNCTION(Client, Reliable, BlueprintCallable)
	void ClientOpenPhotoFolder() const;

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerApplyDefaultSettingsToPlayer();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerApplyPhotoSettingsToPlayer();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerCancelPhotoMode();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerSaveCameraSettings();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerSetupPhotoMode();

protected:
	UPROPERTY(BlueprintAssignable)
	FSavedCameraFoundCallback SavedCameraFoundCallback;

	UPROPERTY(BlueprintAssignable)
	FForcedExitCallback ForcedExitCallback;

	UPROPERTY(BlueprintAssignable)
	FPhotoFinishedRenderingCallback PhotoFinishedRenderingCallback;

	UPROPERTY(BlueprintAssignable)
	FPhotoModeStateChangedCallback PhotoModeStateChangedCallback;

	UPROPERTY(BlueprintAssignable)
	FHandleInputActionCallback HandleInputActionCallback;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_PhotoMode")
	TObjectPtr<UFortInputMappingContext> InputContextPtr;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortControllerComponent_PhotoMode")
	bool bIsCapturingPhoto;

private:
	UFUNCTION(Client, Reliable)
	void ClientExecuteCameraFoundCallback() const;

	UFUNCTION(Client, Reliable)
	void ClientExitPhotoMode();

	UFUNCTION(Client, Reliable)
	void ClientSetupPhotoMode();

	UFUNCTION()
	void ClientUnholstered();

	UPROPERTY(Transient)
	TObjectPtr<AFortCreativePhotoModeCamera> LastPhotoModeCameraPtr;

	UPROPERTY(Transient)
	TObjectPtr<UCameraModifier> PhotoModeModifierPtr;

};

