// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingGameplayActorConsumable.h"
#include "Net/UnrealNetwork.h"

TSubclassOf<UGameplayEffect> ABuildingGameplayActorConsumable::DetermineOnConsumeGameplayEffect_Implementation() const
{
	return TSubclassOf<UGameplayEffect>();
}

UAnimMontage* ABuildingGameplayActorConsumable::DetermineOnConsumeMontage_Implementation() const
{
	return nullptr;
}

TSubclassOf<UFortGameplayAbility> ABuildingGameplayActorConsumable::DetermineOnConsumeMontageAbility_Implementation() const
{
	return TSubclassOf<UFortGameplayAbility>();
}

FTransform ABuildingGameplayActorConsumable::GetDeathFXTransform_Implementation() const
{
	return FTransform();
}

TSubclassOf<UGameplayEffect> ABuildingGameplayActorConsumable::GetOnConsumeGameplayEffect() const
{
	return TSubclassOf<UGameplayEffect>();
}

UAnimMontage* ABuildingGameplayActorConsumable::GetOnConsumeMontage() const
{
	return nullptr;
}

TSubclassOf<UFortGameplayAbility> ABuildingGameplayActorConsumable::GetOnConsumeMontageAbility() const
{
	return TSubclassOf<UFortGameplayAbility>();
}

FGameplayEffectSpecHandle ABuildingGameplayActorConsumable::MakeOnConsumeGameplayEffectSpec(AActor* EventCauser, const int32 Level)
{
	return FGameplayEffectSpecHandle();
}

void ABuildingGameplayActorConsumable::OnAllowedToConsumeFailed_Implementation(const AFortPawn* InteractingPawn)
{
}

bool ABuildingGameplayActorConsumable::OnInteractAllowedToConsume_Implementation(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted)
{
	return false;
}

void ABuildingGameplayActorConsumable::PrepareOnConsumeGameplayEffectSpec_Implementation(FGameplayEffectSpecHandle& SpecHandle)
{
}

void ABuildingGameplayActorConsumable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingGameplayActorConsumable, ItemDefinition);
}
