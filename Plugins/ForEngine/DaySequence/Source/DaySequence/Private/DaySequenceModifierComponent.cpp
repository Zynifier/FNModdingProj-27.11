// Copyright Epic Games, Inc. All Rights Reserved.

#include "DaySequenceModifierComponent.h"

void UDaySequenceModifierComponent::AddBoolOverride(UObject* Object, FName PropertyName, bool bValue)
{
}

void UDaySequenceModifierComponent::AddColorMaterialParameterOverride(UObject* Object, int32 MaterialIndex, FName ParameterName, FLinearColor Value)
{
}

void UDaySequenceModifierComponent::AddColorOverride(UObject* Object, FName PropertyName, FLinearColor Value)
{
}

void UDaySequenceModifierComponent::AddMaterialOverride(UObject* Object, int32 MaterialIndex, UMaterialInterface* Value)
{
}

void UDaySequenceModifierComponent::AddScalarMaterialParameterOverride(UObject* Object, int32 MaterialIndex, FName ParameterName, float Value)
{
}

void UDaySequenceModifierComponent::AddScalarOverride(UObject* Object, FName PropertyName, double Value)
{
}

void UDaySequenceModifierComponent::AddStaticTimeOfDayOverride(ADaySequenceActor* Actor, float Hours)
{
}

void UDaySequenceModifierComponent::AddTransformOverride(UObject* Object, FTransform Value)
{
}

void UDaySequenceModifierComponent::AddVectorOverride(UObject* Object, FName PropertyName, FVector Value)
{
}

void UDaySequenceModifierComponent::AddVisibilityOverride(UObject* Object, bool bValue)
{
}

void UDaySequenceModifierComponent::BindToDaySequenceActor(ADaySequenceActor* DaySequenceActor)
{
}

void UDaySequenceModifierComponent::DisableComponent()
{
}

void UDaySequenceModifierComponent::DisableModifier()
{
}

void UDaySequenceModifierComponent::EnableComponent()
{
}

void UDaySequenceModifierComponent::EnableDistanceVolumeBlends(AActor* InActor)
{
}

void UDaySequenceModifierComponent::EnableModifier()
{
}

float UDaySequenceModifierComponent::GetCurrentBlendWeight() const
{
	return float();
}

bool UDaySequenceModifierComponent::IsBlendTargetInAnyVolume()
{
	return false;
}

bool UDaySequenceModifierComponent::IsNamedSequenceMuted(FName SequenceKey) const
{
	return false;
}

void UDaySequenceModifierComponent::MuteNamedSequence(FName SequenceKey, bool bState)
{
}

void UDaySequenceModifierComponent::OnVolumeOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void UDaySequenceModifierComponent::OnVolumeOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void UDaySequenceModifierComponent::ResetOverrides()
{
}

void UDaySequenceModifierComponent::SetCustomVolumeBlendWeight(float Weight)
{
}

void UDaySequenceModifierComponent::SetUserDaySequence(UDaySequence* InDaySequence)
{
}

void UDaySequenceModifierComponent::SetVolumeCollisionEnabled(const ECollisionEnabled::Type InCollisionType) const
{
}

void UDaySequenceModifierComponent::UnbindFromDaySequenceActor()
{
}
