// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Creative/FortCreativeTags.h"
#include "FortPlaysetSettings.generated.h"

class UTexture2D;

UENUM()
enum class EPlaysetCategory : uint8
{
	Prefab = 0,
	Gallery = 1,
	Device = 2,
	Island = 3,
};

UENUM()
enum class EPlaysetOffsetType : uint8
{
	// Spawn the playset in the upper right corner of the bounding box

	CustomOffsetFromCorner = 0,
	// Spawn the playset at the center of the bounding box

	Center = 1,
};

USTRUCT()
struct FPlaysetSettings
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PlaysetSettings")
	EPlaysetCategory Category;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PlaysetSettings")
	FText Name;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PlaysetSettings")
	FText ShortDescription;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PlaysetSettings", meta=(MultiLine="true"))
	FText LongDescription;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PlaysetSettings")
	TSoftObjectPtr<UTexture2D> SmallThumbnail;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PlaysetSettings")
	TSoftObjectPtr<UTexture2D> LargeThumbnail;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PlaysetSettings", meta=(ShowOnlyInnerProperties))
	FFortCreativeTagsHelper CreativeTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PlaysetSettings")
	bool bAutomaticBoundingBox;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PlaysetSettings", meta=(ClampMin="1", EditCondition="bAutomaticBoundingBox == false", EditConditionHides, HideEditConditionToggle))
	FIntVector BoundingBox;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PlaysetSettings")
	EPlaysetOffsetType OffsetType;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PlaysetSettings")
	float GroundSnapTolerance;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PlaysetSettings", meta=(EditCondition="Category != EPlaysetCategory::Device", EditConditionHides, HideEditConditionToggle))
	bool bGenerateProps;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bGeneratePlayset;
#endif

};

