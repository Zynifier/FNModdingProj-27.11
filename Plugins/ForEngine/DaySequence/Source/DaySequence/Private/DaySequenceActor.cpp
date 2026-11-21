// Copyright Epic Games, Inc. All Rights Reserved.

#include "DaySequenceActor.h"
#include "Net/UnrealNetwork.h"

bool ADaySequenceActor::ContainsDaySequence(const UDaySequence* InDaySequence)
{
	return false;
}

int32 ADaySequenceActor::GetBias(FName SequenceKey)
{
	return int32();
}

float ADaySequenceActor::GetDayLength() const
{
	return float();
}

UDaySequence* ADaySequenceActor::GetDaySequence(FName SequenceName) const
{
	return nullptr;
}

UDaySequence* ADaySequenceActor::GetFirstDaySequence() const
{
	return nullptr;
}

float ADaySequenceActor::GetInitialTimeOfDay() const
{
	return float();
}

UDaySequencePlayer* ADaySequenceActor::GetSequencePlayer() const
{
	return nullptr;
}

float ADaySequenceActor::GetStaticTimeOfDay() const
{
	return float();
}

float ADaySequenceActor::GetTimeOfDay() const
{
	return float();
}

#if WITH_EDITOR
float ADaySequenceActor::GetTimeOfDayPreview() const
{
	return float();
}
#endif

float ADaySequenceActor::GetTimePerCycle() const
{
	return float();
}

bool ADaySequenceActor::HasStaticTimeOfDay() const
{
	return false;
}

bool ADaySequenceActor::IsMuteSequence(FName SequenceKey)
{
	return false;
}

bool ADaySequenceActor::IsPaused() const
{
	return false;
}

bool ADaySequenceActor::IsPlaying() const
{
	return false;
}

void ADaySequenceActor::Multicast_SetTimePerCycle_Implementation(float InHours)
{
}

void ADaySequenceActor::MuteSequence(FName SequenceKey, bool bState)
{
}

void ADaySequenceActor::Pause()
{
}

void ADaySequenceActor::Play()
{
}

void ADaySequenceActor::RemoveStaticTimeOfDay(bool bResumeFromStaticTime)
{
}

void ADaySequenceActor::SetBias(FName SequenceKey, int32 Bias)
{
}

void ADaySequenceActor::SetDaySequence(FName SequenceName, UDaySequence* InDaySequence)
{
}

void ADaySequenceActor::SetReplicatePlayback(bool ReplicatePlayback)
{
}

void ADaySequenceActor::SetStaticTimeOfDay(float InHours)
{
}

bool ADaySequenceActor::SetTimeOfDay(float InHours)
{
	return false;
}

#if WITH_EDITOR
void ADaySequenceActor::SetTimeOfDayPreview(float InHours)
{
}
#endif

void ADaySequenceActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ADaySequenceActor, SequencePlayer);
	DOREPLIFETIME(ADaySequenceActor, DayInterpCurve);
	DOREPLIFETIME(ADaySequenceActor, bUseInterpCurve);
}

bool ADaySequenceActor::RetrieveBindingOverrides(const FGuid& InBindingId, FMovieSceneSequenceID InSequenceID, TArray<UObject*, TInlineAllocator<1>>& OutObjects) const
{
	return false;
}

UObject* ADaySequenceActor::GetInstanceData() const
{
	return nullptr;
}

UMovieSceneSequence* ADaySequenceActor::RetrieveOwnedSequence() const
{
	return nullptr;
}

TSharedPtr<FStructOnScope> ADaySequenceActor::GetObjectPickerProxy(TSharedPtr<IPropertyHandle> ObjectPropertyHandle)
{
	return TSharedPtr<FStructOnScope>();
}

void ADaySequenceActor::UpdateObjectFromProxy(FStructOnScope& Proxy, IPropertyHandle& ObjectPropertyHandle)
{
}
