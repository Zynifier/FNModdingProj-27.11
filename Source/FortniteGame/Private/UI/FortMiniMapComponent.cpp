// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/FortMiniMapComponent.h"
#include "Net/UnrealNetwork.h"

UMaterialInstanceDynamic* UFortMiniMapComponent::GetDynamicMaterial()
{
	return nullptr;
}

bool UFortMiniMapComponent::IsVisibleToPlayer_Implementation(const AFortPlayerController* PC) const
{
	return false;
}

void UFortMiniMapComponent::OnRep_MiniMapData()
{
}

void UFortMiniMapComponent::OverrideLocalMiniMapIcon(UTexture2D* MiniMapIcon)
{
}

void UFortMiniMapComponent::OverrideLocalMiniMapIndicatorIsVisible(bool bVisible)
{
}

void UFortMiniMapComponent::SetMiniMapIcon(UObject* MiniMapIcon)
{
}

void UFortMiniMapComponent::SetMiniMapIconColor(FLinearColor InColor)
{
}

void UFortMiniMapComponent::SetMiniMapIconColorPulsesPerSecond(float ColorPulsesPerSecond)
{
}

void UFortMiniMapComponent::SetMiniMapIconMaterialScalarParameterValue(const FName ParameterName, const float Value)
{
}

void UFortMiniMapComponent::SetMiniMapIconMaterialTextureParameterValue(const FName ParameterName, UTexture* Value)
{
}

void UFortMiniMapComponent::SetMiniMapIconMaterialVectorParameterValue(const FName ParameterName, const FLinearColor Value)
{
}

void UFortMiniMapComponent::SetMiniMapIconPulseColor(FLinearColor PulseColor)
{
}

void UFortMiniMapComponent::SetMiniMapIconScale(const FVector2D& IconScale)
{
}

void UFortMiniMapComponent::SetMiniMapIconSizePulsesPerSecond(float SizePulsesPerSecond)
{
}

void UFortMiniMapComponent::SetMiniMapIndicatorIsVisible(bool bVisible)
{
}

void UFortMiniMapComponent::SetMiniMapIndicatorIsVisibleOnMap(bool bVisibleOnMap)
{
}

void UFortMiniMapComponent::SetMiniMapIndicatorIsVisibleOnMiniMap(bool bVisibleOnMiniMap)
{
}

void UFortMiniMapComponent::SetMiniMapIndicatorTeam(uint8 Team)
{
}

void UFortMiniMapComponent::SetMiniMapLocationOffset(const FVector& LocationOffset)
{
}

void UFortMiniMapComponent::SetMiniMapViewableDistance(float ViewDistance)
{
}

void UFortMiniMapComponent::SetupMiniMapComponent(UTexture2D* MiniMapIcon, FLinearColor IconColor, FLinearColor PulseColor, float ColorPulsesPerSecond, float SizePulsesPerSecond)
{
}

void UFortMiniMapComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMiniMapComponent, MiniMapData);
}
