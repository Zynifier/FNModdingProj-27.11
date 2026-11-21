// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/ShadowProxyMeshComponent.h"

bool UShadowProxyMeshComponent::DoesOwnerUseDynamicDestruction() const
{
	return false;
}

void UShadowProxyMeshComponent::EditorConstruct()
{
}

void UShadowProxyMeshComponent::HandleOwnerDiedClient(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext)
{
}

bool UShadowProxyMeshComponent::IsProxyEnabled(bool bCheckHealth) const
{
	return false;
}

void UShadowProxyMeshComponent::SetForceShadowDisabled(bool bDisable)
{
}

void UShadowProxyMeshComponent::SetShadowSettings(bool bCheckHealth)
{
}
