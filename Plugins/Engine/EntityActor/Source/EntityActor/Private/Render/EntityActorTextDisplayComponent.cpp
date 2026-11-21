// Copyright Epic Games, Inc. All Rights Reserved.

#include "Render/EntityActorTextDisplayComponent.h"
#include "Net/UnrealNetwork.h"

EHorizTextAligment UEntityActorTextDisplayComponent::GetHorizontalAlignment()
{
	return EHorizTextAligment();
}

FVector UEntityActorTextDisplayComponent::GetRelativeLocation()
{
	return FVector();
}

FText UEntityActorTextDisplayComponent::GetText() const
{
	return FText();
}

FColor UEntityActorTextDisplayComponent::GetTextRenderColor() const
{
	return FColor();
}

EVerticalTextAligment UEntityActorTextDisplayComponent::GetVerticalAlignment()
{
	return EVerticalTextAligment();
}

float UEntityActorTextDisplayComponent::GetWorldSize() const
{
	return float();
}

void UEntityActorTextDisplayComponent::OnRep_DisplayText()
{
}

void UEntityActorTextDisplayComponent::OnRep_TextRenderColor()
{
}

void UEntityActorTextDisplayComponent::OnRep_WorldSize()
{
}

void UEntityActorTextDisplayComponent::SetHorizontalAlignment(EHorizTextAligment Value)
{
}

void UEntityActorTextDisplayComponent::SetRelativeLocation(FVector RelativeLocation)
{
}

void UEntityActorTextDisplayComponent::SetRelativeRotation(FRotator RelativeRotation)
{
}

void UEntityActorTextDisplayComponent::SetRelativeScale(FVector RelativeScale)
{
}

void UEntityActorTextDisplayComponent::SetText(FText Text)
{
}

void UEntityActorTextDisplayComponent::SetTextRenderColor(FColor Value)
{
}

void UEntityActorTextDisplayComponent::SetVerticalAlignment(EVerticalTextAligment Value)
{
}

void UEntityActorTextDisplayComponent::SetWorldSize(float Value)
{
}

void UEntityActorTextDisplayComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UEntityActorTextDisplayComponent, DisplayText);
	DOREPLIFETIME(UEntityActorTextDisplayComponent, ShadowVar_WorldSize);
	DOREPLIFETIME(UEntityActorTextDisplayComponent, ShadowVar_TextRenderColor);
}
