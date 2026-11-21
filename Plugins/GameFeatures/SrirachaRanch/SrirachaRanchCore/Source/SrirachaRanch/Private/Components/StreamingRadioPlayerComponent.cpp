// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/StreamingRadioPlayerComponent.h"
#include "Net/UnrealNetwork.h"

UFortBaseStreamingVideo* UStreamingRadioPlayerComponent::GetBaseStreamingVideo()
{
	return nullptr;
}

FFortMediaInBandMetadata UStreamingRadioPlayerComponent::GetMediaMetadata()
{
	return FFortMediaInBandMetadata();
}

FAthenaRadioStation UStreamingRadioPlayerComponent::GetOptionAt(int32 Idx) const
{
	return FAthenaRadioStation();
}

void UStreamingRadioPlayerComponent::HandleLicensedAudioTreatmentChanged(UCPTypes UcpType)
{
}

bool UStreamingRadioPlayerComponent::IsExternalSeat(int32 SeatIdx) const
{
	return false;
}

bool UStreamingRadioPlayerComponent::IsPlayingLiveFeed() const
{
	return false;
}

bool UStreamingRadioPlayerComponent::IsRadioOn() const
{
	return false;
}

void UStreamingRadioPlayerComponent::MediaClose()
{
}

void UStreamingRadioPlayerComponent::MediaClosed()
{
}

void UStreamingRadioPlayerComponent::MediaEnded()
{
}

void UStreamingRadioPlayerComponent::MediaOnSuccess()
{
}

void UStreamingRadioPlayerComponent::MediaResumed()
{
}

void UStreamingRadioPlayerComponent::MediaTerminalError(EBaseMediaTerminalErrorReason Reason)
{
}

void UStreamingRadioPlayerComponent::MetadataChanged(FFortMediaInBandMetadata Metadata)
{
}

void UStreamingRadioPlayerComponent::NativeOnPawnEnterSeat(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex)
{
}

void UStreamingRadioPlayerComponent::NativeOnPawnEnterVehicle(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex)
{
}

void UStreamingRadioPlayerComponent::NativeOnPawnExitSeat(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex)
{
}

void UStreamingRadioPlayerComponent::NativeOnPawnExitVehicle(const TScriptInterface<IFortVehicleInterface>& Vehicle, AFortPawn* PlayerPawn, int32 SeatIndex)
{
}

void UStreamingRadioPlayerComponent::NativeOnVehicleOwnerChanged(const TScriptInterface<IFortVehicleInterface>& Vehicle, const AActor* NewOwner, const AActor* PrevOwner)
{
}

void UStreamingRadioPlayerComponent::OnOwnerDisabledChanged(bool bDisabled)
{
}

void UStreamingRadioPlayerComponent::OnOwnerExploded()
{
}

void UStreamingRadioPlayerComponent::OnOwnerOutOfFuel()
{
}

void UStreamingRadioPlayerComponent::OnOwnerReFueled()
{
}

void UStreamingRadioPlayerComponent::OnOwnerUnpowered()
{
}

void UStreamingRadioPlayerComponent::OnOwningVehicleDied(AFortAthenaVehicle* DeadVehicle, const FGameplayTagContainer& InTags, AController* EventInstigator, AActor* DamageCauser)
{
}

void UStreamingRadioPlayerComponent::OnPiPPlayerBlockedChanged(bool bPiPPlayerBlocking)
{
}

void UStreamingRadioPlayerComponent::OnRep_RadioSourceData()
{
}

void UStreamingRadioPlayerComponent::PlayDefaultIndex()
{
}

void UStreamingRadioPlayerComponent::PlayNextIndex()
{
}

void UStreamingRadioPlayerComponent::PlayPrevIndex()
{
}

void UStreamingRadioPlayerComponent::ServerPlayIndex_Implementation(const int32 InIndex, const EStreamingRadioSourceState InState)
{
}

void UStreamingRadioPlayerComponent::ServerSaveAutoStart_Implementation(const bool bInAutoStart)
{
}

void UStreamingRadioPlayerComponent::ServerSavedSource_Implementation(const FAthenaRadioStation& InSource)
{
}

void UStreamingRadioPlayerComponent::ServerSaveFadeOutTime_Implementation(const float InFadeOutSeconds)
{
}

void UStreamingRadioPlayerComponent::ServerSetDisabledForCurrentPlayerState_Implementation(const bool bInDisableForCurrentPlayerState)
{
}

void UStreamingRadioPlayerComponent::ServerStopRadio_Implementation()
{
}

void UStreamingRadioPlayerComponent::SetActivationRadius(float InRadius)
{
}

void UStreamingRadioPlayerComponent::SetExteriorVolume(const TScriptInterface<IFortVehicleInterface>& Vehicle)
{
}

void UStreamingRadioPlayerComponent::SetInteriorVolume(const TScriptInterface<IFortVehicleInterface>& Vehicle)
{
}

void UStreamingRadioPlayerComponent::SoundMixUpdateTargetingState(bool bNewIsTargeting)
{
}

void UStreamingRadioPlayerComponent::SoundMixUpdateWeaponState(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon)
{
}

void UStreamingRadioPlayerComponent::StartRadio(int32 IdxToPlay, bool bFallbackOverride)
{
}

void UStreamingRadioPlayerComponent::StopIfNoDriver(const TScriptInterface<IFortVehicleInterface>& Vehicle)
{
}

void UStreamingRadioPlayerComponent::StopRadio()
{
}

void UStreamingRadioPlayerComponent::StopRadioWithFadeout(int32 Milliseconds)
{
}

void UStreamingRadioPlayerComponent::ToggleRadioActive()
{
}

void UStreamingRadioPlayerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UStreamingRadioPlayerComponent, bAutostartOnEntry);
	DOREPLIFETIME(UStreamingRadioPlayerComponent, bDisabledForCurrentPlayerState);
	DOREPLIFETIME(UStreamingRadioPlayerComponent, ReplicatedRadioSourceData);
	DOREPLIFETIME(UStreamingRadioPlayerComponent, DefaultPlayingIndex);
	DOREPLIFETIME(UStreamingRadioPlayerComponent, MediaStartTimeFromInit);
}
