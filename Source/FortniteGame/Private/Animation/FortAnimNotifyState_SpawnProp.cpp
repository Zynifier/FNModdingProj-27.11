// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/FortAnimNotifyState_SpawnProp.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Animation/AnimSequenceBase.h"
#include "Animation/AnimationAsset.h"
#include "Athena/FortPlayerPawnAthena.h"
#include "Components/FortPawnComponent_CustomDepth.h"
#include "Components/MeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/Items/AthenaCharacterItemDefinition.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Cosmetics/Variants/FortCosmeticVarianceFlowTypes.h"
#include "Engine/AssetManager.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/StaticMesh.h"
#include "Engine/StreamableManager.h"
#include "Engine/World.h"
#include "FortVehicleInterface.h"
#include "HAL/IConsoleManager.h"
#include "Items/FortItemDefinition.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"
#include "Pawns/FortPawn.h"
#include "Pawns/FortPlayerPawn.h"
#include "SceneTypes.h"
#include "UObject/UnrealType.h"

UFortAnimNotifyState_SpawnProp::UFortAnimNotifyState_SpawnProp(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SocketName = NAME_None;
	Scale = FVector(1.0);
	ActorProp = nullptr;
	SkeletalMeshProp = nullptr;
	SkeletalMeshPropAnimation = nullptr;
	SkeletalMeshPropAnimClass = nullptr;
	bInheritScale = true;
	bUseAttachParentBound = false;
	bPropAnimLooping = true;
	bSyncMontage = false;
	bPrestreamTextures = true;
	PrestreamTextureDuration = 5.0f;
	StaticMeshProp = nullptr;
	bApplyVariantsToSpawnedItems = false;
	bApplyMeshSwappingVariants = false;
	bUseVariantsFromEmoteLeader = false;
	bTrackComponentPropInGC = true;
}

void UFortAnimNotifyState_SpawnProp::PostLoad()
{
	Super::PostLoad();

	RotationOffsetQuat = RotationOffset.Quaternion();
}

#if WITH_EDITOR
void UFortAnimNotifyState_SpawnProp::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UFortAnimNotifyState_SpawnProp, RotationOffset))
	{
		RotationOffsetQuat = RotationOffset.Quaternion();
	}
}
#endif

void UFortAnimNotifyState_SpawnProp::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (!MeshComp || !MeshComp->GetOwner())
	{
		return;
	}

	AFortPawn* FortPawn = Cast<AFortPawn>(MeshComp->GetOwner());
	AFortPlayerPawn* FortPlayerPawn = Cast<AFortPlayerPawn>(FortPawn);
	AFortPlayerPawnAthena* FortPlayerPawnAthena = Cast<AFortPlayerPawnAthena>(FortPawn);

	if (FortPawn && FortPawn->GetNetMode() != NM_DedicatedServer)
	{
		if (FortPawn->EmoteMeshComps.Contains(PropId))
		{
			if (UMeshComponent* ExistingMeshComponent = FortPawn->EmoteMeshComps.FindChecked(PropId))
			{
				ExistingMeshComponent->DestroyComponent();
			}

			FortPawn->EmoteMeshComps.Remove(PropId);
		}

		if (FortPawn->EmotePropActors.Contains(PropId))
		{
			if (AActor* ExistingPropActor = FortPawn->EmotePropActors.FindChecked(PropId))
			{
				ExistingPropActor->Destroy();
			}

			FortPawn->EmotePropActors.Remove(PropId);
		}

		WeakFortPawn = FortPawn;
	}
	else if (!bTrackComponentPropInGC)
	{
		if (!GIsEditor)
		{
			return;
		}

#if WITH_EDITORONLY_DATA
		if (PreviewEmoteMeshComps.Contains(PropId))
		{
			if (UMeshComponent* PreviewMeshComponent = PreviewEmoteMeshComps.FindChecked(PropId))
			{
				PreviewMeshComponent->DestroyComponent();
			}

			PreviewEmoteMeshComps.Remove(PropId);
		}
#endif
	}

	TSubclassOf<AActor> ActorPropToSpawn = ActorProp;
	USkeletalMesh* SkeletalMeshPropToSpawn = SkeletalMeshProp;
	UAnimationAsset* SkeletalMeshPropAnimationToPlay = SkeletalMeshPropAnimation;
	UFortItemDefinition* ActorPropItemDefinition = nullptr;

	GetActorPropOverride(FortPawn, ActorPropToSpawn, SkeletalMeshPropToSpawn, ActorPropItemDefinition);
	GetSkeletalMeshPropOverride(FortPawn, SkeletalMeshPropToSpawn, SkeletalMeshPropAnimationToPlay);

	FVector PropScale = Scale;
	FVector PropLocationOffset = LocationOffset;
	float PropScalar = 1.0f;

	if (FortPlayerPawn)
	{
		if (IFortVehicleInterface* VehicleInterface = FortPlayerPawn->GetVehicleUInterface().GetInterface())
		{
			PropScalar = VehicleInterface->GetSpawnPropOnEmoteScalar();
			if (PropScalar <= 0.0f)
			{
				return;
			}
		}
	}

	PropScale *= PropScalar;
	PropLocationOffset *= PropScalar;

	const bool bSnapIncludingScale = bInheritScale && PropScalar == 1.0f;
	const FAttachmentTransformRules& AttachmentRules = bSnapIncludingScale ? FAttachmentTransformRules::SnapToTargetIncludingScale : FAttachmentTransformRules::SnapToTargetNotIncludingScale;

	if (FortPawn && ActorPropToSpawn)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = FortPawn;
		SpawnParameters.bNoFail = true;
		SpawnParameters.bDeferConstruction = true;

		UWorld* World = FortPawn->GetWorld();
		AActor* PropActor = World->SpawnActor(ActorPropToSpawn.Get(), &FVector::ZeroVector, &FRotator::ZeroRotator, SpawnParameters);
		if (PropActor)
		{
			if (bApplyVariantsToSpawnedItems)
			{
				ApplyVariantsToActor(PropActor, WeakFortPawn, VariantsCosmeticItemDef);
			}

			if (!OverlayMaterials.IsEmpty())
			{
				ApplyOverlayMaterials(PropActor);
			}

			OnActorPropSpawned(PropActor, ActorPropItemDefinition);

			PropActor->FinishSpawning(FTransform::Identity);
			PropActor->SetActorScale3D(PropScale);
			PropActor->AttachToComponent(GetAttachComponent(MeshComp), AttachmentRules, SocketName);

			USceneComponent* PropRootComponent = PropActor->GetRootComponent();
			PropRootComponent->SetRelativeLocation(PropLocationOffset);
			PropRootComponent->SetRelativeRotation(RotationOffsetQuat);
			PropRootComponent->SetAbsolute(false, false, bAbsoluteScale);
			PropRootComponent->bUseAttachParentBound = bUseAttachParentBound;

			FortPawn->EmotePropActors.Add(PropId, PropActor);

			if (FortPlayerPawnAthena)
			{
				ForceCustomDepthUpdate(FortPlayerPawnAthena);
			}
		}

		return;
	}

	AActor* PropOuter = FortPawn ? FortPawn : MeshComp->GetOwner();
	UMeshComponent* PropMeshComponent = nullptr;

	if (!SkeletalMeshPropToSpawn)
	{
		if (!StaticMeshProp)
		{
			return;
		}

		UStaticMeshComponent* StaticMeshComponent = NewObject<UStaticMeshComponent>(PropOuter);
		StaticMeshComponent->SetAbsolute(false, false, bAbsoluteScale);
		StaticMeshComponent->SetRelativeScale3D(PropScale);
		StaticMeshComponent->AttachToComponent(GetAttachComponent(MeshComp), AttachmentRules, SocketName);
		StaticMeshComponent->SetRelativeLocation(PropLocationOffset);
		StaticMeshComponent->SetRelativeRotation(RotationOffsetQuat);
		StaticMeshComponent->bReceivesDecals = false;
		StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		StaticMeshComponent->RegisterComponent();
		StaticMeshComponent->SetStaticMesh(StaticMeshProp);
		StaticMeshComponent->bUseAttachParentBound = bUseAttachParentBound;

		if (PropMaterialScalarParams.Num() > 0)
		{
			if (UMaterialInstanceDynamic* PropMaterialInstance = StaticMeshComponent->CreateAndSetMaterialInstanceDynamic(0))
			{
				for (int32 ParamIndex = 0; ParamIndex < PropMaterialScalarParams.Num(); ++ParamIndex)
				{
					PropMaterialInstance->SetScalarParameterValue(PropMaterialScalarParams[ParamIndex].ParamName, PropMaterialScalarParams[ParamIndex].ParamValue);
				}
			}
		}

		if (bPrestreamTextures)
		{
			StaticMeshComponent->PrestreamTextures(PrestreamTextureDuration, false);
		}

		PropMeshComponent = StaticMeshComponent;

		if (FortPawn)
		{
			FortPawn->EmoteMeshComps.Add(PropId, PropMeshComponent);

			if (FortPlayerPawnAthena)
			{
				ForceCustomDepthUpdate(FortPlayerPawnAthena);
			}
		}
		else
		{
#if WITH_EDITORONLY_DATA
			PreviewEmoteMeshComps.Add(PropId, PropMeshComponent);
#endif

			if (bTrackComponentPropInGC)
			{
				PersistComponents.Add(MeshComp, PropMeshComponent);
			}
		}
	}
	else
	{
		USkeletalMeshComponent* SkeletalMeshComponent = NewObject<USkeletalMeshComponent>(PropOuter);
		SkeletalMeshComponent->SetAbsolute(false, false, bAbsoluteScale);
		SkeletalMeshComponent->SetRelativeScale3D(PropScale);
		SkeletalMeshComponent->AttachToComponent(GetAttachComponent(MeshComp), AttachmentRules, SocketName);
		SkeletalMeshComponent->SetRelativeLocation(PropLocationOffset);
		SkeletalMeshComponent->SetRelativeRotation(RotationOffsetQuat);
		SkeletalMeshComponent->bReceivesDecals = false;
		SkeletalMeshComponent->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
		SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SkeletalMeshComponent->RegisterComponent();
		SkeletalMeshComponent->SetSkeletalMesh(SkeletalMeshPropToSpawn, true);
		SkeletalMeshComponent->bUseAttachParentBound = bUseAttachParentBound;

		if (PropMaterialScalarParams.Num() > 0)
		{
			if (UMaterialInstanceDynamic* PropMaterialInstance = SkeletalMeshComponent->CreateAndSetMaterialInstanceDynamic(0))
			{
				for (int32 ParamIndex = 0; ParamIndex < PropMaterialScalarParams.Num(); ++ParamIndex)
				{
					PropMaterialInstance->SetScalarParameterValue(PropMaterialScalarParams[ParamIndex].ParamName, PropMaterialScalarParams[ParamIndex].ParamValue);
				}
			}
		}

		if (bPrestreamTextures)
		{
			SkeletalMeshComponent->PrestreamTextures(PrestreamTextureDuration, false);
		}

		UAnimInstance* PropAnimInstance = nullptr;
		if (SkeletalMeshPropAnimClass)
		{
			SkeletalMeshComponent->SetAnimInstanceClass(SkeletalMeshPropAnimClass);
			PropAnimInstance = SkeletalMeshComponent->GetAnimInstance();
		}

		if (SkeletalMeshPropAnimationToPlay)
		{
			UAnimMontage* PropMontage = Cast<UAnimMontage>(SkeletalMeshPropAnimationToPlay);
			if (!PropMontage)
			{
				PropMontage = UAnimMontage::CreateSlotAnimationAsDynamicMontage(Cast<UAnimSequenceBase>(SkeletalMeshPropAnimationToPlay), NAME_Default);
			}

			UAnimMontage* MeshMontage = Cast<UAnimMontage>(Animation);

			bool bShouldSyncMontage = false;
			if (PropMontage && MeshMontage)
			{
				if (bSyncMontage || FMath::Abs(MeshMontage->GetPlayLength() - PropMontage->GetPlayLength()) <= KINDA_SMALL_NUMBER)
				{
					bShouldSyncMontage = true;
				}
			}

			bool bFollowMeshMontage = false;
			if (PropAnimInstance)
			{
				PropAnimInstance->Montage_Play(PropMontage, 1.0f, EMontagePlayReturnType::MontageLength, 0.0f, true);
				bFollowMeshMontage = bShouldSyncMontage;
			}
			else if (bShouldSyncMontage)
			{
				SkeletalMeshComponent->PlayAnimation(PropMontage, bPropAnimLooping);
				PropAnimInstance = SkeletalMeshComponent->GetAnimInstance();
				bFollowMeshMontage = true;
			}
			else
			{
				SkeletalMeshComponent->PlayAnimation(SkeletalMeshPropAnimationToPlay, bPropAnimLooping);
			}

			if (bFollowMeshMontage)
			{
				UAnimInstance* MeshAnimInstance = MeshComp->GetAnimInstance();
				if (PropMontage && MeshMontage && MeshAnimInstance && PropAnimInstance)
				{
					FAnimMontageInstance* MeshMontageInstance = MeshAnimInstance->GetActiveInstanceForMontage(MeshMontage);
					FAnimMontageInstance* PropMontageInstance = PropAnimInstance->GetActiveInstanceForMontage(PropMontage);
					if (MeshMontageInstance && PropMontageInstance)
					{
						PropMontageInstance->MontageSync_Follow(MeshMontageInstance);
					}
				}
			}
		}

		if (!FortPawn || FortPawn->WasRecentlyRendered())
		{
			SkeletalMeshComponent->TickAnimation(0.0f, false);
			SkeletalMeshComponent->RefreshBoneTransforms();
		}

		PropMeshComponent = SkeletalMeshComponent;

		if (FortPawn)
		{
			FortPawn->EmoteMeshComps.Add(PropId, PropMeshComponent);

			if (FortPlayerPawn)
			{
				FortPlayerPawn->bSignificanceLODDirty = true;
			}

			if (FortPlayerPawnAthena)
			{
				ForceCustomDepthUpdate(FortPlayerPawnAthena);
			}
		}
		else
		{
#if WITH_EDITORONLY_DATA
			PreviewEmoteMeshComps.Add(PropId, PropMeshComponent);
#endif

			if (bTrackComponentPropInGC)
			{
				PersistComponents.Add(MeshComp, PropMeshComponent);
			}
		}
	}

	if (bApplyVariantsToSpawnedItems)
	{
		ApplyVariantsToComponent(PropMeshComponent);
	}

	if (!OverlayMaterials.IsEmpty())
	{
		ApplyOverlayMaterials(PropMeshComponent);
	}

	OnMeshPropSpawned(PropMeshComponent);
}

void UFortAnimNotifyState_SpawnProp::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (!MeshComp || !MeshComp->GetOwner())
	{
		return;
	}

	if (AFortPawn* FortPawn = Cast<AFortPawn>(MeshComp->GetOwner()))
	{
		if (FortPawn->EmoteMeshComps.Contains(PropId))
		{
			if (UMeshComponent* PropMeshComponent = FortPawn->EmoteMeshComps.FindChecked(PropId))
			{
				PropMeshComponent->DestroyComponent();
			}

			FortPawn->EmoteMeshComps.Remove(PropId);
		}

		if (FortPawn->EmotePropActors.Contains(PropId))
		{
			if (AActor* PropActor = FortPawn->EmotePropActors.FindChecked(PropId))
			{
				PropActor->Destroy();
			}

			FortPawn->EmotePropActors.Remove(PropId);
		}
	}
	else
	{
#if WITH_EDITORONLY_DATA
		if (PreviewEmoteMeshComps.Contains(PropId))
		{
			if (UMeshComponent* PreviewMeshComponent = PreviewEmoteMeshComps.FindChecked(PropId))
			{
				PreviewMeshComponent->DestroyComponent();
			}

			PreviewEmoteMeshComps.Remove(PropId);
		}
#endif

		if (PersistComponents.Contains(MeshComp))
		{
			if (UMeshComponent* PersistMeshComponent = PersistComponents.FindChecked(MeshComp))
			{
				PersistMeshComponent->DestroyComponent();
			}

			PersistComponents.Remove(MeshComp);
		}
	}
}

void UFortAnimNotifyState_SpawnProp::OnMeshPropSpawned(UMeshComponent* MeshPropInstance)
{
	if (!MeshPropInstance)
	{
		return;
	}

	if (AActor* MeshPropOwner = MeshPropInstance->GetOwner())
	{
		if (UPrimitiveComponent* OwnerPrimitiveComponent = MeshPropOwner->FindComponentByClass<UPrimitiveComponent>())
		{
			MeshPropInstance->SetLightingChannels(OwnerPrimitiveComponent->LightingChannels.bChannel0, OwnerPrimitiveComponent->LightingChannels.bChannel1, OwnerPrimitiveComponent->LightingChannels.bChannel2);
		}
	}
}

USceneComponent* UFortAnimNotifyState_SpawnProp::GetAttachComponent(USkeletalMeshComponent* MeshComp) const
{
	AFortPawn* FortPawn = MeshComp ? Cast<AFortPawn>(MeshComp->GetOwner()) : nullptr;
	if (!FortPawn)
	{
		return MeshComp;
	}

	AFortPlayerPawn* FortPlayerPawn = Cast<AFortPlayerPawn>(FortPawn);
	USkeletalMeshComponent* EmotePropAttachMesh = FortPawn->GetEmotePropAttachMesh();

	if (FortPlayerPawn)
	{
		for (const TEnumAsByte<EFortCustomPartType::Type> AttachPartOverride : AttachPartOverrides)
		{
			if (USkeletalMeshComponent* PartMeshComponent = FortPlayerPawn->GetSkeletalMeshForPartType(AttachPartOverride))
			{
				if (USkeletalMesh* PartSkeletalMesh = PartMeshComponent->GetSkeletalMeshAsset())
				{
					if (PartSkeletalMesh->FindSocket(SocketName))
					{
						return PartMeshComponent;
					}
				}
			}
		}
	}

	return EmotePropAttachMesh;
}

void UFortAnimNotifyState_SpawnProp::ApplyOverlayMaterials(UObject* Target)
{
	if (!ensureMsgf(Target && (Target->IsA<AActor>() || Target->IsA<UMeshComponent>()), TEXT("Cannot apply overlay materials to %s - not an actor or mesh component"), *GetNameSafe(Target)))
	{
		return;
	}

	if (!ensureMsgf(!OverlayMaterials.IsEmpty(), TEXT("Cannot apply overlay materials in notify %s - no overlay materials set"), *GetNameSafe(this)))
	{
		return;
	}

	TArray<FSoftObjectPath> OverlayMaterialAssets;
	if (!OverlayMaterials.LowQualityMaterial.IsNull())
	{
		OverlayMaterialAssets.Add(OverlayMaterials.LowQualityMaterial.ToSoftObjectPath());
	}

	if (!OverlayMaterials.HighQualityMaterial.IsNull())
	{
		OverlayMaterialAssets.Add(OverlayMaterials.HighQualityMaterial.ToSoftObjectPath());
	}

	if (ensureMsgf(!OverlayMaterialAssets.IsEmpty(), TEXT("No assets were queued to load for notify %s"), *GetNameSafe(this)))
	{
		UAssetManager::GetStreamableManager().RequestAsyncLoad(OverlayMaterialAssets, FStreamableDelegate::CreateUObject(this, &UFortAnimNotifyState_SpawnProp::OnOverlayMaterialLoaded, TWeakObjectPtr<UObject>(Target)), FStreamableManager::AsyncLoadHighPriority, false, false, TEXT("SpawnPropNotify_OverlayMaterial"));
	}
}

void UFortAnimNotifyState_SpawnProp::OnOverlayMaterialLoaded(TWeakObjectPtr<UObject> WeakTarget)
{
	UObject* Target = WeakTarget.Get();
	if (!Target)
	{
		return;
	}

	static const IConsoleVariable* MaterialQualityLevelCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.MaterialQualityLevel"));
	const int32 MaterialQualityLevel = MaterialQualityLevelCVar ? MaterialQualityLevelCVar->GetInt() : (int32)EMaterialQualityLevel::High;

	TSoftObjectPtr<UMaterialInterface> OverlayMaterialPtr;
	if (OverlayMaterials.LowQualityMaterial.IsNull())
	{
		OverlayMaterialPtr = OverlayMaterials.HighQualityMaterial;
	}
	else if (OverlayMaterials.HighQualityMaterial.IsNull())
	{
		OverlayMaterialPtr = OverlayMaterials.LowQualityMaterial;
	}
	else if (MaterialQualityLevel == EMaterialQualityLevel::Low || MaterialQualityLevel == EMaterialQualityLevel::Medium)
	{
		OverlayMaterialPtr = OverlayMaterials.LowQualityMaterial;
	}
	else
	{
		OverlayMaterialPtr = OverlayMaterials.HighQualityMaterial;
	}

	UMaterialInterface* OverlayMaterial = OverlayMaterialPtr.LoadSynchronous();
	if (!ensureMsgf(OverlayMaterial, TEXT("Unable to load overlay material with path %s"), *OverlayMaterialPtr.ToString()))
	{
		return;
	}

	if (AActor* TargetActor = Cast<AActor>(Target))
	{
		TInlineComponentArray<UMeshComponent*> MeshComponents;
		TargetActor->GetComponents(MeshComponents);

		for (UMeshComponent* MeshComponent : MeshComponents)
		{
			MeshComponent->SetOverlayMaterial(OverlayMaterial);
		}
	}
	else if (UMeshComponent* TargetMeshComponent = Cast<UMeshComponent>(Target))
	{
		TargetMeshComponent->SetOverlayMaterial(OverlayMaterial);
	}
}

void UFortAnimNotifyState_SpawnProp::ApplyVariantsToComponent(UPrimitiveComponent* Component)
{
	UAthenaCosmeticItemDefinition* CosmeticItemDefinition = VariantsCosmeticItemDef.LoadSynchronous();
	AFortPlayerPawn* FortPlayerPawn = WeakFortPawn.IsValid() ? Cast<AFortPlayerPawn>(WeakFortPawn.Get()) : nullptr;

	UAthenaCosmeticItemDefinition* EmoteLeaderCharacterDefinition = nullptr;
	if (bUseVariantsFromEmoteLeader && FortPlayerPawn && FortPlayerPawn->GroupEmoteTailTarget)
	{
		FortPlayerPawn = FortPlayerPawn->GroupEmoteTailTarget;
		EmoteLeaderCharacterDefinition = FortPlayerPawn->GetPawnCosmeticLoadout(false, true).Character;
	}

	if (EmoteLeaderCharacterDefinition)
	{
		CosmeticItemDefinition = EmoteLeaderCharacterDefinition;
	}
	else if (!CosmeticItemDefinition)
	{
		if (!FortPlayerPawn)
		{
			return;
		}

		CosmeticItemDefinition = Cast<UAthenaCosmeticItemDefinition>(FortPlayerPawn->LastEmoteItemDef);
		if (!CosmeticItemDefinition)
		{
			CosmeticItemDefinition = Cast<UAthenaCosmeticItemDefinition>(FortPlayerPawn->LastReplicatedEmoteExecuted);
			if (!CosmeticItemDefinition)
			{
				return;
			}
		}
	}

	if (!FortPlayerPawn)
	{
		return;
	}

	const FFortAthenaLoadout Loadout = FortPlayerPawn->GetPawnCosmeticLoadout(false, true);

	TArray<FSoftObjectPath> VariantAssetsNeeded;
	CosmeticItemDefinition->GatherVariantAssets(nullptr, Loadout, VariantAssetsNeeded, FortPlayerPawn);

	TWeakObjectPtr<UAthenaCosmeticItemDefinition> WeakCosmeticItemDefinition = CosmeticItemDefinition;
	TWeakObjectPtr<UPrimitiveComponent> WeakComponent = Component;
	TWeakObjectPtr<AFortPlayerPawn> WeakPlayerPawn = FortPlayerPawn;

	auto ApplyVariants = [WeakCosmeticItemDefinition, Loadout, WeakComponent, WeakPlayerPawn]()
	{
		if (WeakCosmeticItemDefinition.IsValid() && WeakComponent.IsValid())
		{
			FApplyVariantsAdditionalParams Params;
			Params.WeakPlayerPawn = WeakPlayerPawn;
			WeakCosmeticItemDefinition->ApplyVariantsToComponent(WeakComponent.Get(), Loadout, Params);
		}
	};

	if (VariantAssetsNeeded.ContainsByPredicate([](const FSoftObjectPath& AssetPath) { return !AssetPath.IsNull(); }))
	{
		UAssetManager::GetStreamableManager().RequestAsyncLoad(VariantAssetsNeeded, FStreamableDelegate::CreateLambda(ApplyVariants), FStreamableManager::DefaultAsyncLoadPriority, false, false, TEXT("SpawnPropNotify"));
	}
	else
	{
		ApplyVariants();
	}
}

void UFortAnimNotifyState_SpawnProp::ApplyVariantsToActor(AActor* Actor, TWeakObjectPtr<AFortPawn> InWeakFortPawn, TSoftObjectPtr<UAthenaCosmeticItemDefinition> CosmeticItemDefinitionPtr)
{
	UAthenaCosmeticItemDefinition* CosmeticItemDefinition = CosmeticItemDefinitionPtr.LoadSynchronous();

	if (!InWeakFortPawn.IsValid())
	{
		return;
	}

	AFortPlayerPawn* FortPlayerPawn = Cast<AFortPlayerPawn>(InWeakFortPawn.Get());
	if (!FortPlayerPawn)
	{
		return;
	}

	if (!CosmeticItemDefinition)
	{
		CosmeticItemDefinition = Cast<UAthenaCosmeticItemDefinition>(FortPlayerPawn->LastEmoteItemDef);
		if (!CosmeticItemDefinition)
		{
			CosmeticItemDefinition = Cast<UAthenaCosmeticItemDefinition>(FortPlayerPawn->LastReplicatedEmoteExecuted);
			if (!CosmeticItemDefinition)
			{
				return;
			}
		}
	}

	const FFortAthenaLoadout Loadout = FortPlayerPawn->GetPawnCosmeticLoadout(false, true);

	TArray<FSoftObjectPath> VariantAssetsNeeded;
	CosmeticItemDefinition->GatherVariantAssets(Actor, Loadout, VariantAssetsNeeded, FortPlayerPawn);

	TWeakObjectPtr<UAthenaCosmeticItemDefinition> WeakCosmeticItemDefinition = CosmeticItemDefinition;
	TWeakObjectPtr<AActor> WeakActor = Actor;
	TWeakObjectPtr<AFortPlayerPawn> WeakPlayerPawn = FortPlayerPawn;

	auto ApplyVariants = [WeakCosmeticItemDefinition, Loadout, WeakActor, WeakPlayerPawn]()
	{
		if (WeakCosmeticItemDefinition.IsValid() && WeakActor.IsValid())
		{
			FApplyVariantsAdditionalParams Params;
			Params.WeakPlayerPawn = WeakPlayerPawn;
			WeakCosmeticItemDefinition->ApplyVariants(WeakActor.Get(), Loadout, Params);
		}
	};

	if (VariantAssetsNeeded.ContainsByPredicate([](const FSoftObjectPath& AssetPath) { return !AssetPath.IsNull(); }))
	{
		UAssetManager::GetStreamableManager().RequestAsyncLoad(VariantAssetsNeeded, FStreamableDelegate::CreateLambda(ApplyVariants), FStreamableManager::DefaultAsyncLoadPriority, false, false, TEXT("SpawnPropNotify"));
	}
	else
	{
		ApplyVariants();
	}
}

void UFortAnimNotifyState_SpawnProp::ForceCustomDepthUpdate(AFortPlayerPawnAthena* FortPlayerPawnAthena)
{
	if (UFortPawnComponent_CustomDepth* CustomDepthComponent = FortPlayerPawnAthena->CustomDepthComponent)
	{
		if (CustomDepthComponent->IsRenderCustomDepthEnabled())
		{
			CustomDepthComponent->Update(0.0f, true);
		}
	}
}
