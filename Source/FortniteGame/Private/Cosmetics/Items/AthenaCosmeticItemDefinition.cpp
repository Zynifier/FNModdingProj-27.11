// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"

void UAthenaCosmeticItemDefinition::ApplyVariants(AActor* InActor, const FFortAthenaLoadout& Loadout, const FApplyVariantsAdditionalParams& Params) const
{
}

void UAthenaCosmeticItemDefinition::ApplyVariantsToComponent(UPrimitiveComponent* InComponent, const FFortAthenaLoadout& Loadout, const FApplyVariantsAdditionalParams& Params) const
{
}

void UAthenaCosmeticItemDefinition::GatherVariantAssets(AActor* InActor, const FFortAthenaLoadout& Loadout, TArray<FSoftObjectPath>& VariantAssetsNeeded, AFortPlayerPawn* InPlayerPawn) const
{
}

const FGameplayTagContainer& UAthenaCosmeticItemDefinition::GetAdaptivePlayerStatsList() const
{
	static FGameplayTagContainer Dummy;
	return Dummy;
}

TArray<FString> UAthenaCosmeticItemDefinition::GetAllPossibleNativeMeshComponentNames()
{
	return TArray<FString>();
}

const UFortCosmeticItemAdditionalData* UAthenaCosmeticItemDefinition::GetDataOfType(TSubclassOf<UFortCosmeticItemAdditionalData> Class) const
{
	return nullptr;
}

void UAthenaCosmeticItemDefinition::GetDefaultVariantChannels(TArray<FMcpVariantChannelInfo>& OutDefaultVariantData) const
{
}

const TArray<FFortCosmeticAdaptiveStatPreview>& UAthenaCosmeticItemDefinition::GetItemAdaptiveStatPreviews() const
{
	static TArray<FFortCosmeticAdaptiveStatPreview> Dummy;
	return Dummy;
}

const TArray<FFortCosmeticVariantPreview>& UAthenaCosmeticItemDefinition::GetItemVariantPreviews() const
{
	static TArray<FFortCosmeticVariantPreview> Dummy;
	return Dummy;
}

TArray<FFortCosmeticVariantPreview> UAthenaCosmeticItemDefinition::GetOrGenerateItemVariantPreviews(const AFortPlayerController* PlayerController) const
{
	return TArray<FFortCosmeticVariantPreview>();
}

FRotator UAthenaCosmeticItemDefinition::GetPreviewPawnRotationOffset() const
{
	return FRotator();
}

UFortCosmeticVariant* UAthenaCosmeticItemDefinition::GetVariantChannel(FGameplayTag InVariantChannelTag) const
{
	return nullptr;
}

EVariantUnlockType UAthenaCosmeticItemDefinition::GetVariantUnlockType() const
{
	return EVariantUnlockType();
}

bool UAthenaCosmeticItemDefinition::HasChannelOfType(TSubclassOf<UFortCosmeticVariant> Class) const
{
	return false;
}

bool UAthenaCosmeticItemDefinition::HasModifiableVariants(const UFortItem* InItem) const
{
	return false;
}

bool UAthenaCosmeticItemDefinition::HasVariants() const
{
	return false;
}

bool UAthenaCosmeticItemDefinition::IsEnabledInSTW() const
{
	return false;
}

bool UAthenaCosmeticItemDefinition::IsOwnedByCampaignHero() const
{
	return false;
}

bool UAthenaCosmeticItemDefinition::IsVariantSelectionDisabled(const UObject* InWorldContext) const
{
	return false;
}

void UAthenaCosmeticItemDefinition::UpdateLockedFloatSliderVariant(const AFortPlayerController* FortPC, FGameplayTag ChannelTag) const
{
}
