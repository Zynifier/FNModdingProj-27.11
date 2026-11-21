// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Math/MathFwd.h"
#include "Cosmetics/FortCosmeticOverlayMaterialTypes.h"
#include "FortCustomPartTypeEnum.h"
#include "FortAnimNotifyState_SpawnProp.generated.h"

class AActor;
class UAnimInstance;
class UAnimationAsset;
class UAthenaCosmeticItemDefinition;
class UMeshComponent;
class USkeletalMesh;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FEmotePropMaterialScalarParam
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Materials")
	FName ParamName;

	UPROPERTY(EditAnywhere, Category="Materials")
	float ParamValue;

};

UCLASS(HideCategories=("Object"))
class FORTNITEGAME_API UFortAnimNotifyState_SpawnProp : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify|Attachment")
	TArray<TEnumAsByte<EFortCustomPartType::Type>> AttachPartOverrides;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify|Attachment")
	FName SocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify|Attachment")
	FVector LocationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify|Attachment")
	FRotator RotationOffset;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Scaling")
	FVector Scale;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Props")
	TSubclassOf<AActor> ActorProp;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Props")
	TObjectPtr<USkeletalMesh> SkeletalMeshProp;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Props")
	TObjectPtr<UAnimationAsset> SkeletalMeshPropAnimation;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Props")
	TSubclassOf<UAnimInstance> SkeletalMeshPropAnimClass;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Scaling")
	bool bInheritScale;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Scaling")
	bool bAbsoluteScale;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Scaling")
	bool bUseAttachParentBound;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Settings")
	bool bPropAnimLooping;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Settings")
	bool bSyncMontage;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Settings")
	bool bPrestreamTextures;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Settings")
	float PrestreamTextureDuration;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Props")
	TObjectPtr<UStaticMesh> StaticMeshProp;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Props")
	TArray<FEmotePropMaterialScalarParam> PropMaterialScalarParams;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Props")
	int32 PropId;

	UPROPERTY(EditAnywhere, Category="AnimNotify|Props")
	FFortCosmeticOverlayMaterialData OverlayMaterials;

	UPROPERTY(EditAnywhere, Category="AnimNotify|VariantsSupport")
	TSoftObjectPtr<UAthenaCosmeticItemDefinition> VariantsCosmeticItemDef;

	UPROPERTY(EditAnywhere, Category="AnimNotify|VariantsSupport")
	bool bApplyVariantsToSpawnedItems;

	UPROPERTY(EditAnywhere, Category="AnimNotify|VariantsSupport", meta=(EditCondition="bApplyVariantsToSpawnedItems"))
	bool bApplyMeshSwappingVariants;

	UPROPERTY(EditAnywhere, Category="AnimNotify|VariantsSupport", meta=(EditCondition="bApplyVariantsToSpawnedItems"))
	bool bUseVariantsFromEmoteLeader;

	UPROPERTY(EditAnywhere, Category="AnimNotify|VariantsSupport")
	bool bTrackComponentPropInGC;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<int32, TObjectPtr<UMeshComponent>> PreviewEmoteMeshComps;
#endif

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TMap<TObjectPtr<UMeshComponent>, TObjectPtr<UMeshComponent>> PersistComponents;

};

