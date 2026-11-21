// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralScatterContentSettings.generated.h"

class UProceduralScatterContentVariation;

UENUM()
enum class EProceduralScatterContentPivotMode : uint8
{
	/** Use the object's pivot. */
	UsePivot = 0,
	/** Use the center of the object's tight bounding box. */
	UseBoundingBoxCenter = 1,
	/** Use the center of the lower bound of the object's tight bounding box. */
	UseBoundingBoxBottomCenter = 2,
	/** Use the center of the lower bound of the object's "footprint bounding box" (i.e. lower slice of the object : e.g. a tree can have wide-spread foliage 
	in its upper part but its footprint bounding box will only be as large as its trunk). */
	UseFootprintBoundingBoxBottomCenter = 3,
};

UCLASS(Abstract, EditInlineNew, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object"))
class UProceduralScatterContentSettings : public UObject
{
	GENERATED_BODY()

public:
	/** A list of tags to set on the generated actors. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Actor")
	TArray<FName> SetActorTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Variations")
	TArray<TObjectPtr<UProceduralScatterContentVariation>> Variations;

#if WITH_EDITORONLY_DATA
	// Deprecated properties yard... where old properties go to die...

	UPROPERTY(meta=(DeprecatedProperty))
	FName ActorTag_DEPRECATED;
#endif

};

UCLASS(Abstract, BlueprintType, HideCategories=("Object"))
class UProceduralScatterContentVariation : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variation", meta=(ClampMin="0", UIMin="0"))
	float Weight;

	/** Location of the pivot to use when spawning the object at a scattered point location. */
	UPROPERTY(EditAnywhere, Category="Variation")
	EProceduralScatterContentPivotMode PivotMode;

	/** Additional offset to add to the pivot (in object local space) when spawning the object at a scattered point location. */
	UPROPERTY(EditAnywhere, Category="Variation")
	FVector AdditionalPivotOffset;

	/** Ratio of the object bounding box's total height to consider when computing the object's footprint bounding box (e.g. 0.1 will limit the footprint 
	bounding box to the lower 10% vertices of a static mesh). */
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Variation", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="1"))
	float FootprintBoundingBoxRatio;

	/** A list of tags to set on the generated actors. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Actor")
	TArray<FName> SetActorTags;

};

