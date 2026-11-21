// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/Color.h"
#include "FortSimpleMaterialProgressBar.generated.h"

class UImage;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UWidgetAnimation;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSimpleMaterialProgressBar : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFillAnimationFinished);

public:
	UFUNCTION(BlueprintCallable)
	void AnimateProgressFromCurrent(float End, float AnimSpeed = 1.000000f);

	UFUNCTION(BlueprintCallable)
	void AnimateProgressFromStart(float Start, float End, float AnimSpeed = 1.000000f);

	UFUNCTION(BlueprintCallable)
	void SetColorA(FLinearColor ColorA);

	UFUNCTION(BlueprintCallable)
	void SetColorB(FLinearColor ColorB);

	UFUNCTION(BlueprintCallable)
	void SetColorBackground(FLinearColor ColorBackground);

	UFUNCTION(BlueprintCallable)
	void SetEnableColoredSegments(bool bEnableColoredSegments);

	UFUNCTION(BlueprintCallable)
	void SetProgress(float Progress);

	UFUNCTION(BlueprintCallable)
	void SetSegmentColor(FLinearColor SegmentColor);

	UFUNCTION(BlueprintCallable)
	void SetSegments(int32 NumSegments);

	UFUNCTION(BlueprintCallable)
	void SetStartProgress(float StartProgress);

	UPROPERTY(BlueprintAssignable)
	FOnFillAnimationFinished OnFillAnimationFinished;

private:
	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(InlineEditConditionToggle="CachedColorA"))
	bool bOverrideDefaultColorA;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(DisplayName="Color A", EditCondition="bOverrideDefaultColorA"))
	FLinearColor CachedColorA;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(InlineEditConditionToggle="CachedColorB"))
	bool bOverrideDefaultColorB;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(DisplayName="Color B", EditCondition="bOverrideDefaultColorB"))
	FLinearColor CachedColorB;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(InlineEditConditionToggle="CachedColorBackground"))
	bool bOverrideDefaultColorBackground;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(DisplayName="Color Background", EditCondition="bOverrideDefaultColorBackground"))
	FLinearColor CachedColorBackground;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(InlineEditConditionToggle="bCachedEnableColoredSegments"))
	bool bOverrideDefaultEnableColoredSegments;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(DisplayName="Enable Colored Segments", EditCondition="bOverrideDefaultEnableColoredSegments"))
	bool bCachedEnableColoredSegments;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(InlineEditConditionToggle="CachedSegmentColor"))
	bool bOverrideDefaultSegmentColor;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(DisplayName="Segment Color", EditCondition="bOverrideDefaultSegmentColor"))
	FLinearColor CachedSegmentColor;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(InlineEditConditionToggle="Segments"))
	bool bOverrideDefaultSegments;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(EditCondition="bOverrideDefaultSegments"))
	int32 Segments;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(InlineEditConditionToggle="SegmentEdge"))
	bool bOverrideDefaultSegmentEdge;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(EditCondition="bOverrideDefaultSegmentEdge"))
	float SegmentEdge;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(InlineEditConditionToggle="FillEdgeSoftness"))
	bool bOverrideDefaultFillEdgeSoftness;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(EditCondition="bOverrideDefaultFillEdgeSoftness"))
	float FillEdgeSoftness;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(InlineEditConditionToggle="GlowEdge"))
	bool bOverrideDefaultGlowEdge;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(EditCondition="bOverrideDefaultGlowEdge"))
	float GlowEdge;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(InlineEditConditionToggle="GlowSoftness"))
	bool bOverrideDefaultGlowSoftness;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(EditCondition="bOverrideDefaultGlowSoftness"))
	float GlowSoftness;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(InlineEditConditionToggle="OutlineScale"))
	bool bOverrideDefaultOutlineScale;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(EditCondition="bOverrideDefaultOutlineScale"))
	float OutlineScale;

	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar")
	bool bUseStroke;

	UPROPERTY(EditDefaultsOnly, Category="FortSimpleMaterialProgressBar")
	TObjectPtr<UMaterialInterface> StrokeMaterial;

	UPROPERTY(EditDefaultsOnly, Category="FortSimpleMaterialProgressBar")
	TObjectPtr<UMaterialInterface> NoStrokeMaterial;

	UPROPERTY(EditDefaultsOnly, Category="FortSimpleMaterialProgressBar")
	FName ProgressParamName;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortSimpleMaterialProgressBar", meta=(DisplayName="Design Time Progress"))
	float DesignTime_Progress;
#endif

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSimpleMaterialProgressBar", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Bar;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSimpleMaterialProgressBar", meta=(AllowPrivateAccess, BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> BoundAnim_FillBar;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> CachedMID;

};

