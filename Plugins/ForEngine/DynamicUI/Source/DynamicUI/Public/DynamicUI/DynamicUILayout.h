// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Layout/Margin.h"
#include "Math/MathFwd.h"
#include "Types/SlateEnums.h"
#include "UObject/NoExportTypes.h"
#include "DynamicUI/DynamicUIWidgetTarget.h"
#include "DynamicUILayout.generated.h"

class UDynamicUIConstraintBase;
class UDynamicUIConstraintOverrideBase;

UENUM()
enum class EDynamicUIAnchor : int32
{
	TopLeft = 0,
	TopCenter = 1,
	TopRight = 2,
	CenterLeft = 3,
	CenterCenter = 4,
	CenterRight = 5,
	BottomLeft = 6,
	BottomCenter = 7,
	BottomRight = 8,
	MAX = 9,
};

UENUM()
enum class EDynamicUIAspectRatioType : int32
{
	AspectRatio_1_1 = 0 UMETA(DisplayName="1:1"),
	AspectRatio_4_3 = 1 UMETA(DisplayName="4:3"),
	AspectRatio_5_4 = 2 UMETA(DisplayName="5:4"),
	AspectRatio_16_9 = 3 UMETA(DisplayName="16:9"),
	AspectRatio_16_10 = 4 UMETA(DisplayName="16:10"),
	AspectRatio_21_9 = 5 UMETA(DisplayName="21:9"),
	Custom = 6,
};

UENUM()
enum class EDynamicUIStrength : uint8
{
	Weak = 0,
	Medium = 1,
	Strong = 2,
	Required = 3,
};

USTRUCT()
struct FDynamicUIAspectRatio
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	EDynamicUIAspectRatioType AspectRatio;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(ClampMin="0.100000", EditCondition="AspectRatio == EDynamicUIAspectRatioType::Custom"))
	float CustomAspectRatio;

};

UCLASS(Abstract, EditInlineNew, CollapseCategories, MinimalAPI)
class UDynamicUIConstraintBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Dynamic UI", meta=(DisplayAfter="Anchor", EditCondition="bUseOffset"))
	FVector2D Offset;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Dynamic UI|Override", meta=(EditCondition="bUseOverride"))
	TObjectPtr<UDynamicUIConstraintOverrideBase> ConstraintOverride;

	UPROPERTY(EditAnywhere, Category="Dynamic UI", meta=(InlineEditConditionToggle))
	uint8 bUseOffset : 1;

	UPROPERTY(EditAnywhere, Category="Dynamic UI|Override", meta=(InlineEditConditionToggle))
	uint8 bUseOverride : 1;

};

UCLASS(MinimalAPI, meta=(DisplayName="Alignment"))
class UDynamicUIConstraintAlignment : public UDynamicUIConstraintBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	EDynamicUIAnchor Anchor;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(EditCondition="bUseMaxAspectRatio"))
	FDynamicUIAspectRatio MaxAspectRatio;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	uint8 bUseSafeZone : 1;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(InlineEditConditionToggle))
	uint8 bUseMaxAspectRatio : 1;

};

UCLASS(MinimalAPI, meta=(DisplayName="Container"))
class UDynamicUIConstraintContainer : public UDynamicUIConstraintBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	TArray<FDynamicUIWidgetTarget> WidgetsToContain;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	FMargin Padding;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	uint8 bMustMatchAllWidgets : 1;

};

UCLASS(Abstract, EditInlineNew, CollapseCategories)
class UDynamicUIConstraintOverrideBase : public UObject
{
	GENERATED_BODY()

};

UCLASS(meta=(DisplayName="Platform Specific Override"))
class UDynamicUIConstraintPlatformOverride : public UDynamicUIConstraintOverrideBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="Visibility")
	TMap<FName, TObjectPtr<UDynamicUIConstraintBase>> PlatformVisibilityControls;

	UPROPERTY(EditAnywhere, Instanced, Category="Visibility")
	TMap<ECommonInputType, TObjectPtr<UDynamicUIConstraintBase>> InputTypeVisibilityControls;

};

UCLASS(MinimalAPI, meta=(DisplayName="Position"))
class UDynamicUIConstraintPosition : public UDynamicUIConstraintBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	FVector2D Position;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	EDynamicUIAnchor Anchor;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	uint8 bUseSafeZone : 1;

};

UCLASS(MinimalAPI, meta=(DisplayName="Replace"))
class UDynamicUIConstraintReplace : public UDynamicUIConstraintBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	FDynamicUIWidgetTarget TargetWidget;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Dynamic UI", meta=(DisplayAfter="ConstraintOverride", EditCondition="bUseFallbacks"))
	TArray<TObjectPtr<UDynamicUIConstraintBase>> Fallbacks;

	UPROPERTY(EditAnywhere, Category="Dynamic UI", meta=(InlineEditConditionToggle))
	uint8 bUseFallbacks : 1;

};

UCLASS(MinimalAPI, meta=(DisplayName="Widget"))
class UDynamicUIConstraintWidget : public UDynamicUIConstraintBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	EDynamicUIAnchor Anchor;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	FDynamicUIWidgetTarget TargetWidget;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	EDynamicUIAnchor TargetAnchor;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Dynamic UI", meta=(DisplayAfter="ConstraintOverride", EditCondition="bUseFallbacks"))
	TArray<TObjectPtr<UDynamicUIConstraintBase>> Fallbacks;

	UPROPERTY(EditAnywhere, Category="Dynamic UI", meta=(DisplayAfter="Offset"))
	uint8 bConstrainToUnallowedWidgets : 1;

	UPROPERTY(EditAnywhere, Category="Dynamic UI", meta=(InlineEditConditionToggle))
	uint8 bUseFallbacks : 1;

};

