// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortInteractInterface.h"
#include "FortInteractContextInfo.generated.h"

class AActor;
class UFortInteractContextInfoWidget;
class UObject;
class UPrimitiveComponent;
class USoundBase;
class UTexture2D;
class UUserWidget;

UENUM(BlueprintType)
enum class EFortInteractContextInfoType : uint8
{
	Standard = 0,
	Crafting = 1,
};

UCLASS(Transient, MinimalAPI, BlueprintType)
class UFortInteractContextInfo : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool HasValidContextOverride() const;

	UFUNCTION(BlueprintPure)
	bool HasValidSecondContextOverride() const;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	FText ContextText;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	FLinearColor ContextTextColor;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	FText ContextSubText;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	FLinearColor ContextSubTextColor;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	TSoftObjectPtr<UTexture2D> ContextSubTextImage;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	TSubclassOf<UFortInteractContextInfoWidget> ContextOverrideWidget;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	TSubclassOf<UFortInteractContextInfoWidget> SecondContextOverrideWidget;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	FText SecondContextText;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	FLinearColor SecondContextTextColor;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	FText SecondContextSubText;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	FLinearColor SecondContextSubTextColor;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	FText ErrorText;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	FGameplayTag ErrorIconTag;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	TWeakObjectPtr<AActor> ReceivingActor;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortInteractContextInfo")
	TWeakObjectPtr<UPrimitiveComponent> InteractComponent;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	FGameplayTagContainer DynamicInteractionOptions;

	UPROPERTY()
	TObjectPtr<UObject> OptionalObjectData;

	UPROPERTY()
	TObjectPtr<USoundBase> LongInteractSound;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortInteractContextInfo", meta=(EditInline="true"))
	TObjectPtr<UUserWidget> OptionalHUDDisplayWidget;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	FVector InteractPoint;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	TEnumAsByte<EInteractionBeingAttempted> InteractionBeingAttempted;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	float RequiredDuration;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	float SecondRequiredDuration;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	bool bShowCountDown;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	bool bShowFirstInteraction;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	bool bShowSecondInteraction;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	bool bShowSecondInteractionKeybind;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	bool bIsSecondInteractionActive;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	bool bDisplayTextOnly;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	bool bDisplaySubInteractIcon;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	bool bSuppressInteractionWidget;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	bool bHasCustomInteractionWidget;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	bool bSuppressSimpleInteractionWidgetForTouch;

	UPROPERTY(BlueprintReadOnly, Category="FortInteractContextInfo")
	EFortInteractContextInfoType InteractContextInfoType;

};

