// Copyright Epic Games, Inc. All Rights Reserved.

#include "Widgets/VerseFortniteUIFSlider.h"
#include "Net/UnrealNetwork.h"

void UVerseFortniteUIFrameworkSlider::ExecuteServerValueChanged(float InNewValue, int32 InClientID, int32 InServerID)
{
}

float UVerseFortniteUIFrameworkSlider::GetMaxValue() const
{
	return float();
}

float UVerseFortniteUIFrameworkSlider::GetMinValue() const
{
	return float();
}

float UVerseFortniteUIFrameworkSlider::GetStepSize() const
{
	return float();
}

float UVerseFortniteUIFrameworkSlider::GetValue() const
{
	return float();
}

void UVerseFortniteUIFrameworkSlider::HandleValueChanged(float NewValue)
{
}

void UVerseFortniteUIFrameworkSlider::OnRep_MaxValue()
{
}

void UVerseFortniteUIFrameworkSlider::OnRep_MinValue()
{
}

void UVerseFortniteUIFrameworkSlider::OnRep_StepSize()
{
}

void UVerseFortniteUIFrameworkSlider::OnRep_Value()
{
}

void UVerseFortniteUIFrameworkSlider::ServerValueChanged_Implementation(APlayerController* PlayerController, float InNewValue, int32 InClientID, int32 InServerID)
{
}

void UVerseFortniteUIFrameworkSlider::SetMaxValue(float InMaxValue)
{
}

void UVerseFortniteUIFrameworkSlider::SetMinValue(float InMinValue)
{
}

void UVerseFortniteUIFrameworkSlider::SetStepSize(float InMinValue)
{
}

bool UVerseFortniteUIFrameworkSlider::SetValue(float InValue)
{
	return false;
}

void UVerseFortniteUIFrameworkSlider::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UVerseFortniteUIFrameworkSlider, Value);
	DOREPLIFETIME(UVerseFortniteUIFrameworkSlider, MinValue);
	DOREPLIFETIME(UVerseFortniteUIFrameworkSlider, MaxValue);
	DOREPLIFETIME(UVerseFortniteUIFrameworkSlider, StepSize);
}
