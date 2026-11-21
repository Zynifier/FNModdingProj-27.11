// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FrontEnd/ItemPreview/FortItemPreviewMultiAngleActor.h"
#include "FortItemPreviewOnPawnActor.generated.h"

class AFortPlayerParachute;
class AFortPlayerPawn;
class AFortWeapon;
class UAnimMontage;
class UCameraComponent;
class UChildActorComponent;
class USceneComponent;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class AFortItemPreviewOnPawnActor : public AFortItemPreviewMultiAngleActor, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	FVector GetPawnLocation() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInBodyCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutTallBodyCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInTallBodyCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutBackpackCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInBackpackCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutSkydiveCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInSkydiveCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutEmoteCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInEmoteCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutEmoteHighCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInEmoteHighCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutEmoticonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInEmoticonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutPickaxeCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInPickaxeCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutDualPickaxeCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInDualPickaxeCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutDoubleWristPickaxeCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInDoubleWristPickaxeCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutPersonalGliderCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInPersonalGliderCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutCharacterCustomizerCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInCharacterCustomizerCameraComponent;

private:
	UFUNCTION()
	void HandleContrailsActivated();

	UFUNCTION()
	void HandlePawnCustomizationComplete(AFortPlayerPawn* Pawn);

	UFUNCTION()
	void OnMontageStopped(UAnimMontage* Montage, bool bInterrupted);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UChildActorComponent> HeroPawnComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOnPawnActor", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<USceneComponent> LoadingFXPosition;

	UPROPERTY(Transient)
	TObjectPtr<AFortWeapon> EquippedWeapon;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerParachute> EquippedParachute;

	UPROPERTY(EditAnywhere, Category="FortItemPreviewOnPawnActor", meta=(AllowPrivateAccess="TRUE"))
	float ContrailGlideVerticalVelocity;

	UPROPERTY(EditAnywhere, Category="FortItemPreviewOnPawnActor", meta=(AllowPrivateAccess="TRUE"))
	float ContrailDiveVerticalVelocity;

	UPROPERTY(EditAnywhere, Category="FortItemPreviewOnPawnActor", meta=(AllowPrivateAccess="TRUE", ClampMin="0.000000"))
	float EmotePlayDelay;

	UPROPERTY(EditAnywhere, Category="FortItemPreviewOnPawnActor", meta=(AllowPrivateAccess="TRUE", ClampMin="0.000000"))
	float EmoteFXDuration;

	UPROPERTY(EditAnywhere, Category="FortItemPreviewOnPawnActor", meta=(AllowPrivateAccess="TRUE"))
	FGameplayTagContainer PickaxeHitTags;

};

