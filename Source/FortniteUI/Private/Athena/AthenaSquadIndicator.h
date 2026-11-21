// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/AthenaMarkedActorIndicator.h"
#include "AthenaSquadIndicator.generated.h"

class UAthenaMarkerConfirmationWidget;
class UImage;
class UMaterialInterface;
class UTexture2D;
class UWidgetAnimation;

USTRUCT(BlueprintType)
struct FMarkerLargeIndicatorType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MarkerLargeIndicatorType")
	TObjectPtr<UMaterialInterface> MarkerMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MarkerLargeIndicatorType")
	FVector2D ImageSize;

};

UCLASS(Abstract)
class UAthenaSquadIndicator : public UAthenaMarkedActorIndicator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemIconSet(const UTexture2D* NewIcon);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	float IndicatorWorldOffsetProperty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	float IndicatorItemOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	float IndicatorSpecialServerOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	FVector2D SmallIndicatorScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	float WorldOffsetInterpValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	FName MIDParam_LocationColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	FName MIDParam_ItemIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	FName MIDParam_ItemRarityColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	FName MIDParam_SquadCommsPingIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	FName MIDParam_NPCCommandPingIconCrop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	TObjectPtr<UTexture2D> LoadingPlaceholder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSquadIndicator")
	FMarkerLargeIndicatorType LocationMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSquadIndicator")
	FMarkerLargeIndicatorType ItemMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSquadIndicator")
	FMarkerLargeIndicatorType DangerMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSquadIndicator")
	FMarkerLargeIndicatorType SpecialLocalMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSquadIndicator")
	FMarkerLargeIndicatorType SpecialServerMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSquadIndicator")
	FMarkerLargeIndicatorType SquadCommsMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSquadIndicator")
	UMaterialInterface* DefaultIconMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSquadIndicator")
	UMaterialInterface* SquadCommsPingMaterial;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSquadIndicator", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_SmallIndicator;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSquadIndicator", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LocationFlare;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSquadIndicator", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LargeIndicator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaSquadIndicator", meta=(AllowPrivateAccess="TRUE", BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> Anim_LocationPlaced;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaSquadIndicator", meta=(AllowPrivateAccess="TRUE", BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> Anim_DangerPlaced;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaSquadIndicator", meta=(AllowPrivateAccess="TRUE", BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> Anim_ItemPlaced;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaSquadIndicator", meta=(AllowPrivateAccess="TRUE", BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> Anim_Hovered;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSquadIndicator", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_TrajectoryLargeIndicator;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSquadIndicator", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_TrajectorySmallIndicator;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSquadIndicator", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaMarkerConfirmationWidget> MarkerConfirmationWidget;

};

