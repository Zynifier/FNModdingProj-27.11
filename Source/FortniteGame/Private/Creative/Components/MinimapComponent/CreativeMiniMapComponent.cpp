// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/MinimapComponent/CreativeMiniMapComponent.h"
#include "Net/UnrealNetwork.h"

void UCreativeMiniMapComponent::ApplyColorOverridesToMaterial(const ECreativeMinimapComponentIconColorType Color) const
{
}

void UCreativeMiniMapComponent::ApplyIconTextureOverridesToMaterial(const FName ParameterName, UTexture2D* Icon) const
{
}

void UCreativeMiniMapComponent::ApplyLinearColorOverridesToMaterial(const FLinearColor& Color) const
{
}

void UCreativeMiniMapComponent::ApplyScalarOverridesToMaterial(const FName ParameterName, const float Value) const
{
}

void UCreativeMiniMapComponent::ApplyVectorOverridesToMaterial(const FName ParameterName, const FLinearColor Value) const
{
}

void UCreativeMiniMapComponent::OnRep_IconData()
{
}

void UCreativeMiniMapComponent::SetIndicatorIconColor(const FLinearColor& IndicatorIconColor)
{
}

void UCreativeMiniMapComponent::SetIndicatorText(const FText& IndicatorText)
{
}

void UCreativeMiniMapComponent::SetIndicatorTextColor(const FLinearColor& IndicatorTextColor)
{
}

void UCreativeMiniMapComponent::SetIndicatorTextOffset(const FVector2D& IndicatorTextOffset)
{
}

void UCreativeMiniMapComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCreativeMiniMapComponent, IndicatorTextProperties);
	DOREPLIFETIME(UCreativeMiniMapComponent, IconData);
}
