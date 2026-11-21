// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "CreativeDynamicUITypes.generated.h"

UENUM(BlueprintType)
enum class ECreativeDynamicUIAlignment : uint8
{
	TopLeft = 0,
	TopCenter = 1,
	TopRight = 2,
	MiddleLeft = 3,
	Centered = 4,
	MiddleRight = 5,
	BottomLeft = 6,
	BottomCenter = 7,
	BottomRight = 8,
	CenteredFull = 9,
	LeftTall = 10,
	CenteredTall = 11,
	RightTall = 12,
	TopWide = 13,
	CenteredWide = 14,
	BottomWide = 15,
};

UENUM(BlueprintType)
enum class ECreativeDynamicUIAnchor : uint8
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
};

UENUM(BlueprintType)
enum class ECreativeDynamicUIAspectRatioType : uint8
{
	None = 0,
	AspectRatio_1_1 = 1 UMETA(DisplayName="1:1"),
	AspectRatio_4_3 = 2 UMETA(DisplayName="4:3"),
	AspectRatio_5_4 = 3 UMETA(DisplayName="5:4"),
	AspectRatio_16_9 = 4 UMETA(DisplayName="16:9"),
	AspectRatio_16_10 = 5 UMETA(DisplayName="16:10"),
	AspectRatio_21_9 = 6 UMETA(DisplayName="21:9"),
};

UENUM(BlueprintType)
enum class ECreativeDynamicUILayoutConstraintType : uint8
{
	None = 0,
	Alignment = 1,
};

UENUM(BlueprintType)
enum class ECreativeDynamicUISizeModifierType : uint8
{
	None = 0,
	Fixed = 1,
	Scale = 2,
};

USTRUCT(BlueprintType)
struct FCreativeDynamicUIAlignmentConstraint
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="CreativeDynamicUIAlignmentConstraint")
	ECreativeDynamicUIAlignment Alignment;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="CreativeDynamicUIAlignmentConstraint")
	ECreativeDynamicUIAnchor Anchor;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="CreativeDynamicUIAlignmentConstraint")
	ECreativeDynamicUIAspectRatioType AspectRatio;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="CreativeDynamicUIAlignmentConstraint")
	FVector2D Offset;

};

USTRUCT(BlueprintType)
struct FCreativeDynamicUIFixedSizeModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="CreativeDynamicUIFixedSizeModifier")
	FVector2f Size;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="CreativeDynamicUIFixedSizeModifier")
	bool bUseRenderTransform;

};

USTRUCT(BlueprintType)
struct FCreativeDynamicUIScaleSizeModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="CreativeDynamicUIScaleSizeModifier")
	FVector2f Scale;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="CreativeDynamicUIScaleSizeModifier")
	bool bUseRenderTransform;

};

