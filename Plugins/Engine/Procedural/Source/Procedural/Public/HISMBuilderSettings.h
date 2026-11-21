// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavRelevantInterface.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/EngineTypes.h"
#include "PhysicsEngine/BodyInstance.h"
#include "UObject/NoExportTypes.h"
#include "VT/RuntimeVirtualTextureEnum.h"
#include "HISMBuilderSettings.generated.h"

class URuntimeVirtualTexture;

UCLASS(EditInlineNew, MinimalAPI, BlueprintType, HideCategories=("Object"))
class UHISMBuilderSettings : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Procedural HISM Builder Settings")
	int32 GetOverriddenLightMapRes() const;

	UFUNCTION(BlueprintCallable, Category="Procedural HISM Builder Settings")
	void SetOverriddenLightMapRes(int32 Value);

	/** Mobility property to apply to the generated HISM components */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings")
	TEnumAsByte<EComponentMobility::Type> Mobility;

	/**
	 * The distance where instances will begin to fade out if using a PerInstanceFadeAmount material node. 0 disables.
	 * When the entire cluster is beyond this distance, the cluster is completely culled and not rendered at all.
	 */
	UPROPERTY(EditAnywhere, Category="InstanceSettings", meta=(UIMin="0"))
	FInt32Interval CullDistance;

	/** Scale applied to change the computation of LOD distances when using the StaticMesh screen sizes. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings")
	float LODDistanceScale;

	/** Controls whether the HISM should cast a shadow or not. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings")
	uint8 bCastShadow : 1;

	/** Controls whether the generated HISM should inject light into the Light Propagation Volume.  This flag is only used if bCastShadow is true. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings", meta=(EditCondition="bCastShadow"))
	uint8 bAffectDynamicIndirectLighting : 1;

	/** Controls whether the primitive should affect dynamic distance field lighting methods.  This flag is only used if bCastShadow is true. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings", meta=(EditCondition="bCastShadow"))
	uint8 bAffectDistanceFieldLighting : 1;

	/** Controls whether the generated HISM should cast shadows in the case of non precomputed shadowing.  This flag is only used if bCastShadow is true. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings", meta=(EditCondition="bCastShadow"))
	uint8 bCastDynamicShadow : 1;

	/** Whether the generated HISM should cast a static shadow from shadow casting lights.  This flag is only used if bCastShadow is true. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings", meta=(EditCondition="bCastShadow"))
	uint8 bCastStaticShadow : 1;

	/** Whether this generated HISM should cast dynamic shadows as if it were a two sided material. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="InstanceSettings", meta=(EditCondition="bCastDynamicShadow"))
	uint8 bCastShadowAsTwoSided : 1;

	/** Whether the generated HISM receives decals. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="InstanceSettings")
	uint8 bReceivesDecals : 1;

	/** Whether to override the lightmap resolution defined in the static mesh. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings", meta=(InlineEditConditionToggle))
	uint8 bOverrideLightMapRes : 1;

	/** Overrides the lightmap resolution defined in the static mesh */
	UPROPERTY(EditAnywhere, BlueprintSetter=SetOverriddenLightMapRes, Category="InstanceSettings", meta=(DisplayName="Light Map Resolution", EditCondition="bOverrideLightMapRes"))
	int32 OverriddenLightMapRes;

	/** Controls the type of lightmap used for this component. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="InstanceSettings")
	ELightmapType LightmapType;

	/**
	 * If enabled, generated HISM will render a pre-pass which allows it to occlude other primitives, and also allows
	 * it to correctly receive DBuffer decals. Enabling this setting may have a negative performance impact.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="InstanceSettings")
	uint8 bUseAsOccluder : 1;

	/** Custom collision for generated HISM */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings", meta=(HideObjectType="TRUE"))
	FBodyInstance BodyInstance;

	/** Force navmesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings", meta=(HideObjectType="TRUE"))
	TEnumAsByte<EHasCustomNavigableGeometry::Type> CustomNavigableGeometry;

	/**
	 * Lights with matching channels will affect the generated HISM.
	 * These channels only apply to opaque materials, direct lighting, and dynamic lighting and shadowing.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="InstanceSettings")
	FLightingChannels LightingChannels;

	/** If true, the generated HISM will be rendered in the CustomDepth pass (usually used for outlines) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="InstanceSettings", meta=(DisplayName="Render CustomDepth Pass"))
	uint8 bRenderCustomDepth : 1;

	/** Mask used for stencil buffer writes. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="InstanceSettings", meta=(editcondition="bRenderCustomDepth"))
	ERendererStencilMask CustomDepthStencilWriteMask;

	/** Optionally write this 0-255 value to the stencil buffer in CustomDepth pass (Requires project setting or r.CustomDepth == 3) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="InstanceSettings", meta=(DisplayName="CustomDepth Stencil Value", editcondition="bRenderCustomDepth", UIMax="255", UIMin="0"))
	int32 CustomDepthStencilValue;

	/**
	 * Translucent objects with a lower sort priority draw behind objects with a higher priority.
	 * Translucent objects with the same priority are rendered from back-to-front based on their bounds origin.
	 * This setting is also used to sort objects being drawn into a runtime virtual texture.
	 *
	 * Ignored if the object is not translucent.  The default priority is zero.
	 * Warning: This should never be set to a non-default value unless you know what you are doing, as it will prevent the renderer from sorting correctly.
	 * It is especially problematic on dynamic gameplay effects.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings")
	int32 TranslucencySortPriority;

	/**
	 * Whether the generated HISM component should be affected by the Engine Scalability system's scalability setting.
	 * Enable for detail meshes that don't really affect the game. Disable for anything important.
	 * Typically, this will be enabled for small meshes without collision (e.g. grass) and disabled for large meshes with collision (e.g. trees)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Scalability")
	uint8 bEnableDensityScaling : 1;

	/**
	 * Array of runtime virtual textures into which we draw the instances.
	 * The mesh material also needs to be set up to output to a virtual texture.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VirtualTexture", meta=(DisplayName="Draw in Virtual Textures"))
	TArray<TObjectPtr<URuntimeVirtualTexture>> RuntimeVirtualTextures;

	/**
	 * Number of lower mips in the runtime virtual texture to skip for rendering this primitive.
	 * Larger values reduce the effective draw distance in the runtime virtual texture.
	 * This culling method doesn't take into account primitive size or virtual texture size.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="VirtualTexture", meta=(DisplayName="Virtual Texture Skip Mips", UIMax="15", UIMin="0"))
	int32 VirtualTextureCullMips;

	/** Controls if this component draws in the main pass as well as in the virtual texture. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VirtualTexture", meta=(DisplayName="Draw in Main Pass"))
	ERuntimeVirtualTextureMainPassType VirtualTextureRenderPassType;

};

