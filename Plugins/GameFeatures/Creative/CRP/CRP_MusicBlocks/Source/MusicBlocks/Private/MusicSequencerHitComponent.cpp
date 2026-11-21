// Copyright Epic Games, Inc. All Rights Reserved.

#include "MusicSequencerHitComponent.h"
#include "Net/UnrealNetwork.h"

UMusicSequencerHitComponent* AMusicSequencerHitActor::GetMusicSequencerHitComponent() const
{
	return nullptr;
}

AMusicSequencerHitActor* UMusicSequencerHitAdderComponent::GetMusicSequencerHitActor() const
{
	return nullptr;
}

bool UMusicSequencerHitComponent::AddMusicSequencerActor(TScriptInterface<IFortMusicSequencerInterface> HitInterface)
{
	return false;
}

bool UMusicSequencerHitComponent::AddSequenceHitEvent(TScriptInterface<IFortMusicSequencerInterface> HitInterface, const AController* Instigator)
{
	return false;
}

void UMusicSequencerHitComponent::OnSequenceHitEventExpired(FMusicSequencerHitHandle ExpiredHandle)
{
}

bool UMusicSequencerHitComponent::ProcessSequenceHitEvent(const FMusicSequencerHitEntry& Event)
{
	return false;
}

bool UMusicSequencerHitComponent::RegisterMusicSequencerActor(const UObject* WorldContextObject, TScriptInterface<IFortMusicSequencerInterface> Actor)
{
	return false;
}

bool UMusicSequencerHitComponent::ReplicateMusicSequencerHit(const UObject* WorldContextObject, TScriptInterface<IFortMusicSequencerInterface> HitInterface, const AController* Instigator)
{
	return false;
}

void UMusicSequencerHitComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UMusicSequencerHitComponent, MusicSequencerEventList);
	DOREPLIFETIME(UMusicSequencerHitComponent, LoadedSoundsList);
}
