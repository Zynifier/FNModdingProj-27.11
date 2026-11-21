// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/FortAnimNotifyState_EmoteSound.h"
#include "Animation/AnimSequenceBase.h"
#include "Athena/FortCharacterVehicle_Ostrich.h"
#include "AudioDevice.h"
#include "Components/AudioComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Customization/FortPlayerMannequin.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "FortVehicleInterface.h"
#include "HAL/IConsoleManager.h"
#include "Kismet/GameplayStatics.h"
#include "NativeGameplayTags.h"
#include "Pawns/FortPawn.h"
#include "Pawns/FortPlayerPawn.h"
#include "Sound/AudioAnalysis/FortAudioAnalysisSubsystem.h"
#include "Sound/FortAudioTypes.h"
#include "Sound/MusicEventSubsystem/MusicEventSubsystem.h"
#include "Sound/SoundAttenuation.h"
#include "Sound/SoundBase.h"
#include "Sound/SoundClass.h"
#include "Sound/SoundEffectSource.h"

UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_MusicEventSubsystem_Event_Emote_1P, "MusicEventSubsystem.Event.Emote.1P");
UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_MusicEventSubsystem_Event_Emote_3P, "MusicEventSubsystem.Event.Emote.3P");
UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_MusicEventSubsystem_Event_Emote_3P_FrontEnd, "MusicEventSubsystem.Event.Emote.3P.FrontEnd");

static int32 GEnableFoleyEmoteMusicEventRegistration = 0;
static FAutoConsoleVariableRef CVarEnableFoleyEmoteMusicEventRegistration(
	TEXT("au.MusicEventSubsystem.EnableFoleyEmoteMusicEventRegistration"),
	GEnableFoleyEmoteMusicEventRegistration,
	TEXT("Toggles on/off registration of Foley emotes with the subsystem\n0: Disable, 1: Enable"),
	ECVF_Default);

UFortAnimNotifyState_EmoteSound::UFortAnimNotifyState_EmoteSound(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	EmoteSound1P = nullptr;
	EmoteSound3P = nullptr;
	bPrimarySound = true;
	SoundName = NAME_None;
	FadeOutTime = 0.5f;
	bEmoteLeaderOnly = false;
	bStopAudioOnNotifyEnd = true;
	AttachName = FName(TEXT("pelvis"));
#if WITH_EDITORONLY_DATA
	PreviewComp = nullptr;
#endif
}

void UFortAnimNotifyState_EmoteSound::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp || !Animation)
	{
		UE_LOG(LogScript, VeryVerbose, TEXT("%s: Either MeshComp or Animation is nullptr! MeshComp: %s, Animation: %s"), ANSI_TO_TCHAR(__FUNCTION__), *GetNameSafe(MeshComp), *GetNameSafe(Animation));
		return;
	}

	FName SoundId;
	if (bPrimarySound)
	{
		SoundId = Animation->GetFName();
	}
	else
	{
		if (SoundName.IsNone())
		{
			UE_LOG(LogScript, Warning, TEXT("UFortAnimNotifyState_EmoteSound::NotifyBegin: Non-Primary Sounds need SoundId specifier!   Animation: [%s]"), *Animation->GetName());
			return;
		}

		SoundId = SoundName;
	}

	if (!MeshComp->GetOwner())
	{
		return;
	}

	AFortPawn* FortPawn = Cast<AFortPawn>(MeshComp->GetOwner());
	AFortPlayerPawn* FortPlayerPawn = Cast<AFortPlayerPawn>(FortPawn);

	if (bEmoteLeaderOnly && FortPlayerPawn && FortPlayerPawn->GroupEmoteTailTarget)
	{
		return;
	}

	if (FortPawn)
	{
		if (!FortPawn->AreEmoteAudioComponentsAllowed())
		{
			return;
		}

		USoundBase* SoundToPlay = EmoteSound3P;
		USoundEffectSourcePresetChain* SourceEffectChain = FortPawn->InGameEmoteSoundEffectSoundPresetChain;
		USoundAttenuation* AttenuationSettings = nullptr;
		USkeletalMeshComponent* AttachComponent = MeshComp;
		bool bIsFirstPerson = false;
		bool bIsFrontEnd = false;

		if (FortPlayerPawn)
		{
			const uint8 FrontEndMode = FortPlayerPawn->FrontEndMode;
			if (FrontEndMode == 1 || FrontEndMode == 2)
			{
				AttenuationSettings = FortPlayerPawn->FrontEndEmoteAudioAttenuation;
				bIsFrontEnd = true;
			}
			else
			{
				AttenuationSettings = FortPlayerPawn->InGameEmoteAudioAttenuation;
			}

			if (FortPlayerPawn->IsLocallyControlled() || FortPlayerPawn->bIsLocalPlayer || FrontEndMode == 2)
			{
				bIsFirstPerson = true;
				SoundToPlay = EmoteSound1P;
			}

			if (IFortVehicleInterface* VehicleInterface = FortPlayerPawn->GetVehicleUInterface().GetInterface())
			{
				VehicleInterface->OnEmoteAudioStarted();

				if (USoundEffectSourcePresetChain* VehicleSourceEffectChain = VehicleInterface->GetEmoteSoundEffectSourcePresetChain())
				{
					SourceEffectChain = VehicleSourceEffectChain;
				}

				if (USoundAttenuation* VehicleAttenuationSettings = VehicleInterface->GetEmoteAudioAttenuation())
				{
					AttenuationSettings = VehicleAttenuationSettings;
				}
			}

			if (AFortCharacterVehicle_Ostrich* Ostrich = Cast<AFortCharacterVehicle_Ostrich>(FortPlayerPawn))
			{
				USkeletalMeshComponent* OstrichMesh = Ostrich->GetEmoteMesh();
				if (ensure(OstrichMesh))
				{
					AttachComponent = OstrichMesh;
				}

				if (UAudioComponent* ExistingAudioComponent = FortPawn->GetEmoteAudioComponent(SoundId))
				{
					Ostrich->bEmoteAudioForceStopped = true;
					ExistingAudioComponent->Stop();
					FortPawn->EmoteAudioComps.Remove(SoundId);
				}
			}
		}

		UAudioComponent* AudioComponent = SpawnAudioComponent(SoundToPlay, AttachComponent, AttachName, FVector::ZeroVector, EAttachLocation::SnapToTarget, false, 1.0f, 1.0f, 0.0f, AttenuationSettings, nullptr, true);
		if (!AudioComponent)
		{
			return;
		}

		if (SourceEffectChain)
		{
			AudioComponent->SetSourceEffectChain(SourceEffectChain);
		}

		AudioComponent->Play();

		if (UWorld* World = FortPawn->GetWorld())
		{
			if (UMusicEventSubsystem* MusicEventSubsystem = UGameInstance::GetSubsystem<UMusicEventSubsystem>(World->GetGameInstance()))
			{
				if (ShouldRegisterWithMusicEventSubsystem(AudioComponent->Sound))
				{
					MusicEventSubsystem->AddEventByComponent(AudioComponent, GetMusicEventTag(bIsFirstPerson, bIsFrontEnd), FGameplayTagContainer());
				}
			}
		}

		if (UAudioComponent* ExistingAudioComponent = FortPawn->GetEmoteAudioComponent(SoundId))
		{
			ExistingAudioComponent->FadeOut(FadeOutTime, 0.0f);
			FortPawn->EmoteAudioComps.Remove(SoundId);
		}

		if (FortPawn->AreEmoteAudioComponentsAllowed())
		{
			FEmoteAudioComponentData EmoteAudioComponentData;
			EmoteAudioComponentData.AudioComponent = AudioComponent;
			EmoteAudioComponentData.FadeOutTime = FadeOutTime;
			EmoteAudioComponentData.EmoteItemDefinition = FortPawn->LastEmoteItemDef;
			EmoteAudioComponentData.bShouldPersistOverMontages = false;
			FortPawn->EmoteAudioComps.Add(SoundId, EmoteAudioComponentData);
		}
	}
	else if (AFortPlayerMannequin* PlayerMannequin = Cast<AFortPlayerMannequin>(MeshComp->GetOwner()))
	{
		if (!PlayerMannequin->bAllowEmoteAudioComponents)
		{
			return;
		}

		UAudioComponent* AudioComponent = SpawnAudioComponent(EmoteSound3P, MeshComp, AttachName, FVector::ZeroVector, EAttachLocation::SnapToTarget, false, 1.0f, 1.0f, 0.0f, nullptr, nullptr, true);
		if (!AudioComponent)
		{
			return;
		}

		AudioComponent->Play();

		if (UWorld* World = PlayerMannequin->GetWorld())
		{
			if (UFortAudioAnalysisSubsystem* AudioAnalysisSubsystem = World->GetSubsystem<UFortAudioAnalysisSubsystem>())
			{
				AudioAnalysisSubsystem->RegisterDefaultSubmix();
			}

			if (UMusicEventSubsystem* MusicEventSubsystem = UGameInstance::GetSubsystem<UMusicEventSubsystem>(World->GetGameInstance()))
			{
				if (ShouldRegisterWithMusicEventSubsystem(AudioComponent->Sound))
				{
					const FGameplayTag EventTag = MusicEventTagOverride3P.IsValid() ? MusicEventTagOverride3P : FGameplayTag(TAG_MusicEventSubsystem_Event_Emote_3P);
					MusicEventSubsystem->AddEventByComponent(AudioComponent, EventTag, FGameplayTagContainer());
				}
			}
		}

		if (UAudioComponent* ExistingAudioComponent = PlayerMannequin->GetEmoteAudioComponent(SoundId))
		{
			ExistingAudioComponent->FadeOut(FadeOutTime, 0.0f);
		}

		if (PlayerMannequin->bAllowEmoteAudioComponents)
		{
			PlayerMannequin->EmoteAudioComponents.Add(SoundId, AudioComponent);
		}
	}
	else
	{
#if WITH_EDITORONLY_DATA
		if (PreviewComp)
		{
			PreviewComp->FadeOut(FadeOutTime, 0.0f);
		}

		PreviewComp = UGameplayStatics::SpawnSoundAttached(EmoteSound3P, MeshComp, NAME_None, FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::SnapToTarget, false, 1.0f, 1.0f, 0.0f, nullptr, nullptr, true);
#endif
	}
}

void UFortAnimNotifyState_EmoteSound::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp || !Animation)
	{
		return;
	}

	FName SoundId;
	if (bPrimarySound)
	{
		SoundId = Animation->GetFName();
	}
	else
	{
		if (SoundName.IsNone())
		{
			return;
		}

		SoundId = SoundName;
	}

	if (!MeshComp->GetOwner())
	{
		return;
	}

	AFortPawn* FortPawn = Cast<AFortPawn>(MeshComp->GetOwner());
	AFortPlayerPawn* FortPlayerPawn = Cast<AFortPlayerPawn>(FortPawn);

	if (bEmoteLeaderOnly && FortPlayerPawn && FortPlayerPawn->GroupEmoteTailTarget)
	{
		return;
	}

	UAudioComponent* AudioComponent = FortPawn ? FortPawn->GetEmoteAudioComponent(SoundId) : nullptr;
	if (AudioComponent)
	{
		AFortCharacterVehicle_Ostrich* Ostrich = Cast<AFortCharacterVehicle_Ostrich>(FortPawn);
		if (Ostrich && Ostrich->bEmoteAudioForceStopped)
		{
			Ostrich->bEmoteAudioForceStopped = false;
		}
		else if (bStopAudioOnNotifyEnd)
		{
			AudioComponent->FadeOut(FadeOutTime, 0.0f);
			FortPawn->EmoteAudioComps.Remove(SoundId);

			if (UWorld* World = AudioComponent->GetWorld())
			{
				if (UMusicEventSubsystem* MusicEventSubsystem = UGameInstance::GetSubsystem<UMusicEventSubsystem>(World->GetGameInstance()))
				{
					MusicEventSubsystem->RemoveEvent(AudioComponent);
				}
			}
		}

		if (FortPlayerPawn)
		{
			if (IFortVehicleInterface* VehicleInterface = FortPlayerPawn->GetVehicleUInterface().GetInterface())
			{
				VehicleInterface->OnEmoteAudioStopped();
			}
		}
	}
	else if (AFortPlayerMannequin* PlayerMannequin = Cast<AFortPlayerMannequin>(MeshComp->GetOwner()))
	{
		if (UAudioComponent* MannequinAudioComponent = PlayerMannequin->GetEmoteAudioComponent(SoundId))
		{
			MannequinAudioComponent->FadeOut(FadeOutTime, 0.0f);
			PlayerMannequin->EmoteAudioComponents.Remove(SoundId);

			if (UWorld* World = MannequinAudioComponent->GetWorld())
			{
				if (UFortAudioAnalysisSubsystem* AudioAnalysisSubsystem = World->GetSubsystem<UFortAudioAnalysisSubsystem>())
				{
					AudioAnalysisSubsystem->UnRegisterDefaultSubmix();
				}

				if (UMusicEventSubsystem* MusicEventSubsystem = UGameInstance::GetSubsystem<UMusicEventSubsystem>(World->GetGameInstance()))
				{
					MusicEventSubsystem->RemoveEvent(nullptr);
				}
			}
		}
	}
	else
	{
#if WITH_EDITORONLY_DATA
		if (PreviewComp)
		{
			PreviewComp->FadeOut(FadeOutTime, 0.0f);
		}
#endif
	}
}

UAudioComponent* UFortAnimNotifyState_EmoteSound::SpawnAudioComponent(USoundBase* Sound, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, EAttachLocation::Type LocationType, bool bStopWhenAttachedToDestroyed, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, bool bAutoDestroy) const
{
	if (!Sound)
	{
		return nullptr;
	}

	if (!AttachToComponent)
	{
		UE_LOG(LogScript, Warning, TEXT("UFortAnimNotifyState_EmoteSound::SpawnAudioComponent: NULL AttachComponent specified! Trying to spawn sound [%s],"), *Sound->GetName());
		return nullptr;
	}

	UWorld* const ThisWorld = AttachToComponent->GetWorld();
	if (ThisWorld && ThisWorld->IsNetMode(NM_DedicatedServer))
	{
		return nullptr;
	}

	FVector TestLocation = Location;
	if (LocationType == EAttachLocation::KeepRelativeOffset)
	{
		if (AttachPointName != NAME_None)
		{
			TestLocation = AttachToComponent->GetSocketTransform(AttachPointName).TransformPosition(Location);
		}
		else
		{
			TestLocation = AttachToComponent->GetComponentTransform().TransformPosition(Location);
		}
	}
	else if (LocationType == EAttachLocation::SnapToTarget || LocationType == EAttachLocation::SnapToTargetIncludingScale)
	{
		TestLocation = AttachToComponent->GetSocketLocation(AttachPointName);
	}

	FAudioDevice::FCreateComponentParams Params(ThisWorld, AttachToComponent->GetOwner());
	Params.SetLocation(TestLocation);
	Params.bStopWhenOwnerDestroyed = bStopWhenAttachedToDestroyed;
	Params.AttenuationSettings = AttenuationSettings;

	if (ConcurrencySettings)
	{
		Params.ConcurrencySet.Add(ConcurrencySettings);
	}

	UAudioComponent* AudioComponent = FAudioDevice::CreateComponent(Sound, Params);
	if (AudioComponent)
	{
		if (UWorld* ComponentWorld = AudioComponent->GetWorld())
		{
			const bool bIsInGameWorld = ComponentWorld->IsGameWorld();

			if (LocationType == EAttachLocation::SnapToTarget || LocationType == EAttachLocation::SnapToTargetIncludingScale)
			{
				AudioComponent->AttachToComponent(AttachToComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, AttachPointName);
			}
			else
			{
				AudioComponent->AttachToComponent(AttachToComponent, FAttachmentTransformRules::KeepRelativeTransform, AttachPointName);
				if (LocationType == EAttachLocation::KeepWorldPosition)
				{
					AudioComponent->SetWorldLocationAndRotation(Location, FRotator::ZeroRotator);
				}
				else
				{
					AudioComponent->SetRelativeLocationAndRotation(Location, FRotator::ZeroRotator);
				}
			}

			AudioComponent->SetVolumeMultiplier(VolumeMultiplier);
			AudioComponent->SetPitchMultiplier(PitchMultiplier);
			AudioComponent->bAllowSpatialization = Params.ShouldUseAttenuation();
			AudioComponent->bIsUISound = !bIsInGameWorld;
			AudioComponent->bAutoDestroy = bAutoDestroy;
			AudioComponent->SubtitlePriority = Sound->GetSubtitlePriority();
		}
	}

	return AudioComponent;
}

bool UFortAnimNotifyState_EmoteSound::ShouldRegisterWithMusicEventSubsystem(USoundBase* Sound) const
{
	if (!Sound)
	{
		return false;
	}

	if (MusicEventTagOverride1P.IsValid() || MusicEventTagOverride3P.IsValid())
	{
		return true;
	}

	USoundClass* SoundClass = Sound->GetSoundClass();
	if (!SoundClass)
	{
		return false;
	}

	return SoundClass->PassiveSoundMixModifiers.Num() != 0 || GEnableFoleyEmoteMusicEventRegistration != 0;
}

FGameplayTag UFortAnimNotifyState_EmoteSound::GetMusicEventTag(bool bIsFirstPerson, bool bIsFrontEnd) const
{
	if (bIsFirstPerson)
	{
		return MusicEventTagOverride1P.IsValid() ? MusicEventTagOverride1P : FGameplayTag(TAG_MusicEventSubsystem_Event_Emote_1P);
	}

	if (bIsFrontEnd)
	{
		return TAG_MusicEventSubsystem_Event_Emote_3P_FrontEnd;
	}

	return MusicEventTagOverride3P.IsValid() ? MusicEventTagOverride3P : FGameplayTag(TAG_MusicEventSubsystem_Event_Emote_3P);
}
