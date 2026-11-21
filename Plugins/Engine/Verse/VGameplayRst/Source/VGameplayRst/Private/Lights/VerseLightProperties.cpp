// Copyright Epic Games, Inc. All Rights Reserved.

#include "Lights/VerseLightProperties.h"
#include "Net/UnrealNetwork.h"

void UVerseLightPropertiesBase::OnRep_Intensity()
{
}

void UVerseLightPropertiesBase::OnRep_LightColor()
{
}

void UVerseLightPropertiesBase::OnRep_LightComponent()
{
}

void UVerseLightPropertiesBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UVerseLightPropertiesBase, Intensity);
	DOREPLIFETIME(UVerseLightPropertiesBase, LightColor);
	DOREPLIFETIME(UVerseLightPropertiesBase, LightComponent);
}

void UVerseLocalLightProperties::OnRep_AttenuationRadius()
{
}

void UVerseLocalLightProperties::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UVerseLocalLightProperties, AttenuationRadius);
}

void UVersePointLightProperties::OnRep_SourceLength()
{
}

void UVersePointLightProperties::OnRep_SourceRadius()
{
}

void UVersePointLightProperties::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UVersePointLightProperties, SourceRadius);
	DOREPLIFETIME(UVersePointLightProperties, SourceLength);
}

void UVerseSpotLightProperties::OnRep_InnerConeAngle()
{
}

void UVerseSpotLightProperties::OnRep_OuterConeAngle()
{
}

void UVerseSpotLightProperties::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UVerseSpotLightProperties, InnerConeAngle);
	DOREPLIFETIME(UVerseSpotLightProperties, OuterConeAngle);
}
