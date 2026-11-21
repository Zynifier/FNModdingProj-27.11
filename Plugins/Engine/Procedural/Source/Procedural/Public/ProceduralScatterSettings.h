// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralScatterSettings.generated.h"

class UProceduralContentVariationsWeightsModifier;
class UProceduralDensityModifier;
class UProceduralRotationModifier;
class UProceduralScaleModifier;
class UProceduralScatterContentSettings;

USTRUCT(BlueprintType)
struct FProceduralContentVariationsModifiers
{
	GENERATED_BODY()

public:
	/** Density modifier stack. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Content")
	TArray<TObjectPtr<UProceduralContentVariationsWeightsModifier>> Modifiers;

};

USTRUCT(BlueprintType)
struct FProceduralDensityModifiers
{
	GENERATED_BODY()

public:
	/** Density modifier stack. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Density")
	TArray<TObjectPtr<UProceduralDensityModifier>> Modifiers;

};

USTRUCT(BlueprintType)
struct FProceduralRotationModifiers
{
	GENERATED_BODY()

public:
	/** Rotation modifier stack. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Rotation")
	TArray<TObjectPtr<UProceduralRotationModifier>> Modifiers;

};

USTRUCT(BlueprintType)
struct FProceduralScaleModifiers
{
	GENERATED_BODY()

public:
	/** Initial random scale. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Scale", meta=(InlineEditConditionToggle))
	bool bRandomScaleEnabled;

	/** Initial random scale. */
	UPROPERTY(EditAnywhere, Category="Scale", meta=(ClampMax="10", ClampMin="0.001", EditCondition="bRandomScaleEnabled", UIMax="10", UIMin="0.001"))
	FFloatInterval RandomScale;

	/** Scale modifier stack. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Scale")
	TArray<TObjectPtr<UProceduralScaleModifier>> Modifiers;

};

USTRUCT(BlueprintType)
struct FProceduralScatterTargetSurface
{
	GENERATED_BODY()

public:
	/** Whether to scatter on landscape */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSurface")
	bool bAllowLandscape;

	/** Whether to scatter on BSP */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSurface")
	bool bAllowBSP;

	/** Whether to scatter on StaticMesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSurface")
	bool bAllowStaticMesh;

	/** Whether to scatter on translucent geometry */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSurface")
	bool bAllowTranslucent;

	/** Whether to scatter on actor's surface if hit actor has any of the specified tags. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Tags")
	TArray<FName> AllowedActorTags;

	/** Whether to exclude actor's surface if hit actor has any of the specified tags. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Tags")
	TArray<FName> DisallowedActorTags;

	/** Whether to scatter on actor component's surface if hit component has any of the specified tags. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Tags")
	TArray<FName> AllowedComponentTags;

	/** Whether to exclude actor component's surface if hit component has any of the specified tags. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Tags")
	TArray<FName> DisallowedComponentTags;

};

// Defines Object that contains all necessary settings for scatter generator

UCLASS(EditInlineNew, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object"))
class UProceduralScatterSettings : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Procedural Scatter Settings")
	float GetSourcePointDistanceMax() const;

	UFUNCTION(BlueprintPure, Category="Procedural Scatter Settings")
	float GetSourcePointDistanceMin() const;

	UFUNCTION(BlueprintCallable, Category="Procedural Scatter Settings")
	void SetSourcePointDistanceMax(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Scatter Settings")
	void SetSourcePointDistanceMin(float InValue);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Content")
	TObjectPtr<UProceduralScatterContentSettings> Content;

	/** If checked, content variations modifiers will be applied. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Content", meta=(InlineEditConditionToggle))
	uint8 bContentVariationsModifiersEnabled : 1;

	/** Content variations modifiers. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Content", meta=(EditCondition="bContentVariationsModifiersEnabled"))
	FProceduralContentVariationsModifiers ContentVariationsModifiers;

	/** A list of tags to set on scattered points (so that they can be used as source points in a subsequent scatterer). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PointTags")
	TArray<FName> SetPointTags;

	/** The minimum distance between points */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DistributionFootprint", meta=(ClampMax="100000", ClampMin="0", EditCondition="!bAutomaticCollisionRadius", UIMax="100000", UIMin="0"))
	float CollisionRadius;

	/** If checked, Collision Radius is automatically computed based on asset variation content (typically object bounds). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DistributionFootprint")
	uint8 bAutomaticCollisionRadius : 1;

	/** If checked, automatic collision radius is computed based on spherical object bounds rather than the diagonal of box-shaped bounds (can be tighter, depending on the asset). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DistributionFootprint", meta=(EditCondition="bAutomaticCollisionRadius"))
	uint8 bUseSphericalBoundsForAutomaticCollisionRadius : 1;

	/** Scale factor applied to the collision radius automatically computed from variation content. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DistributionFootprint", meta=(ClampMax="100000", ClampMin="0", EditCondition="bAutomaticCollisionRadius", UIMax="100000", UIMin="0"))
	float AutomaticCollisionRadiusScaleFactor;

	/** The seed that determines placement of points. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DuplicateTransient, AdvancedDisplay, Category="Distribution")
	int32 DistributionSeed;

	/** If checked, density modifiers will be applied. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Distribution", meta=(InlineEditConditionToggle))
	uint8 bDensityModifiersEnabled : 1;

	/** Density modifiers. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Distribution", meta=(EditCondition="bDensityModifiersEnabled"))
	FProceduralDensityModifiers DensityModifiers;

	/** Specifies the number of points to scatter per 100 square meters (10m x 10m area). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DensityDistribution", meta=(ClampMax="10000.0", ClampMin="0.0", UIMax="10000.0", UIMin="0.0"))
	float Density;

	/** A list of tags that the point cloud points can have in order to act as source points for this scatterer (i.e. if the point has Tag[0] OR Tag[1] OR ..., it will act as a source point) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SourcePointDistribution")
	TArray<FName> SourcePointTagIncludes;

	/** A list of tags that the point cloud points cannot have in order to act as source points for this scatterer (i.e. if the point has Tag[0] OR Tag[1] OR ..., it will NOT act as a source point) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SourcePointDistribution")
	TArray<FName> SourcePointTagExcludes;

	/** A list of tags that an actor can have in order to act as source points for this scatterer (i.e. if the actor has Tag[0] OR Tag[1] OR ..., it will act as a source point) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SourcePointDistribution")
	TArray<FName> SourceActorTagIncludes;

	/** A list of tags that an actor cannot have in order to act as source points for this scatterer (i.e. if the actor has Tag[0] OR Tag[1] OR ..., it will NOT act as a source point) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SourcePointDistribution")
	TArray<FName> SourceActorTagExcludes;

	/** A list of tags that one of an actor's components can have in order to act as source points for this scatterer (i.e. if the component has Tag[0] OR Tag[1] OR ..., it will act as a source point) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SourcePointDistribution")
	TArray<FName> SourceComponentTagIncludes;

	/** A list of tags that one of an actor's components cannot have in order to act as source points for this scatterer (i.e. if the component has Tag[0] OR Tag[1] OR ..., it will NOT act as a source point) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SourcePointDistribution")
	TArray<FName> SourceComponentTagExcludes;

	/** The distance range to scatter around the source points. */
	UPROPERTY(EditAnywhere, Category="SourcePointDistribution", meta=(ClampMin="0", UIMin="0"))
	FFloatInterval SourcePointDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SourcePointDistribution", meta=(InlineEditConditionToggle))
	uint8 bUseSourcePointExactNumber : 1;

	/** Specifies the exact number of points to scatter around source point. If not set, Density will be used. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SourcePointDistribution", meta=(ClampMin="1", EditCondition="bUseSourcePointExactNumber", UIMin="1"))
	int32 SourcePointExactNumber;

	/** If checked, scale modifiers will be applied. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Scale", meta=(InlineEditConditionToggle))
	uint8 bScaleModifiersEnabled : 1;

	/** Scale modifiers. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Scale", meta=(EditCondition="bScaleModifiersEnabled"))
	FProceduralScaleModifiers ScaleModifiers;

	/** If checked, rotation modifiers will be applied. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Orientation", meta=(InlineEditConditionToggle))
	uint8 bRotationModifiersEnabled : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Orientation", meta=(EditCondition="bRotationModifiersEnabled"))
	FProceduralRotationModifiers RotationModifiers;

	/** Whether scattered points normal should have their angle to match the surface normal. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Orientation")
	uint8 bAlignToNormal : 1;

	/** The maximum angle in degrees that scattered points normal will be adjusted away from the vertical */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Orientation", meta=(ClampMax="359", ClampMin="0", EditCondition="bAlignToNormal", UIMax="359", UIMin="0", Units="deg"))
	float AlignMaxAngle;

	/** Scatter surface filtering options */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filtering")
	FProceduralScatterTargetSurface TargetSurface;

	/* If checked, a test is performed to detect overhanging ledge cases before each point is placed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filtering")
	uint8 bDetectOverhangingLedge : 1;

	/* Tweaking value for the overhanging ledge detection : number of ray cast performed around the scattered point to detect a ledge (if a single ray cast hits nothing, the object is considered on a ledge). */
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Filtering", meta=(ClampMin="1", EditCondition="bDetectOverhangingLedge", UIMin="1"))
	int32 OverhangingLedgeDetectionRayCount;

	/* Tweaking value for the overhanging ledge detection : length of the ray cast (scaled by the asset's scale). */
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Filtering", meta=(ClampMin="1", EditCondition="bDetectOverhangingLedge", UIMin="1"))
	float OverhangingLedgeDetectionLength;

	/* Tweaking value for the overhanging ledge detection : (negative) vertical offset for the ray cast's start position (scaled by the asset's scale). e.g. 30cm means the ray cast will start 30cm under the scatter point in the scattered point's Z direction. */
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Filtering", meta=(ClampMin="1", EditCondition="bDetectOverhangingLedge", UIMin="1"))
	float OverhangingLedgeDetectionVerticalThreshold;

	/* Tweaking value for the overhanging ledge detection : scale factor for the asset's footprint bounds radius (i.e. scale of the radius of the ray casts circle around the scattered point). */
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Filtering", meta=(ClampMin="0.01", EditCondition="bDetectOverhangingLedge", UIMin="0.01"))
	float OverhangingLedgeDetectionRadiusScale;

	/** Scale value under which point will not be placed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Filtering", meta=(ClampMin="0", UIMin="0"))
	float FilterMinimumScale;

	/**
	 * When two points overlap we must determine which point to remove.
	 * The point with a lower OverlapPriority will be removed.
	 * In the case where OverlapPriority is the same, we fallback on radius regular simulation rules apply.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filtering")
	float OverlapPriority;

	/* If checked, an overlap test with existing world geometry is performed before each point is placed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CollisionFiltering")
	uint8 bCollisionWithWorld : 1;

	/* The scattered point's collision bounding box will be scaled by the specified amount before performing the overlap check */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CollisionFiltering", meta=(EditCondition="bCollisionWithWorld"))
	FVector CollisionScale;

	/* The color used to represent debug display of this point */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	FColor DebugColor;

#if WITH_EDITORONLY_DATA
	// Deprecated properties yard... where old properties go to die...

	UPROPERTY(meta=(DeprecatedProperty))
	FName SourcePointTag_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(meta=(DeprecatedProperty))
	FName SourceActorTag_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(meta=(DeprecatedProperty))
	FName SourceComponentTag_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(meta=(DeprecatedProperty))
	FName PointTag_DEPRECATED;
#endif

};

