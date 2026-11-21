// Copyright Epic Games, Inc. All Rights Reserved.

#include "ViewModels/ItemShop/FortItemShopVM.h"

void UFortItemShopVM::ClearItemShopBang() const
{
}

const UFortItemShopOfferVM* UFortItemShopVM::FindOfferByTrackingId(const FString& OfferTrackingId) const
{
	return nullptr;
}

const UFortItemShopOfferVM* UFortItemShopVM::GetFirstOfferVMFromLayout(const FFortItemShopLayout& InLayout) const
{
	return nullptr;
}

bool UFortItemShopVM::GetHasSeenItemShop() const
{
	return false;
}

const UFortItemShopOfferVM* UFortItemShopVM::GetOfferFromId(const FString& OfferId) const
{
	return nullptr;
}

const UFortItemShopOfferGroupVM* UFortItemShopVM::GetOfferGroupWithOffer(const FString& OfferId) const
{
	return nullptr;
}

FFortItemShopCMSBackground UFortItemShopVM::GetPreferredBackgroundForLayout(const FFortItemShopLayout& InLayout) const
{
	return FFortItemShopCMSBackground();
}

const UFortItemShopSectionVM* UFortItemShopVM::GetSection(const FString& SectionId) const
{
	return nullptr;
}

const UFortItemShopSectionVM* UFortItemShopVM::GetSubsection(const FString& SubsectionId, const UFortItemShopSectionVM* ParentSection) const
{
	return nullptr;
}

bool UFortItemShopVM::IsItemPreviewEnabled() const
{
	return false;
}

bool UFortItemShopVM::IsRufusOnePageShopEnabled() const
{
	return false;
}

bool UFortItemShopVM::LoadBackground(const FFortItemShopCMSBackground& Background, const FOnBackgroundLoaded& OnLoadedCallback)
{
	return false;
}

bool UFortItemShopVM::MPItemShopPhase2Enabled() const
{
	return false;
}

void UFortItemShopVM::SetHasSeenItemShop(bool bHasSeen) const
{
}

bool UFortItemShopVM::ShouldShowNavPromptBelowNav() const
{
	return false;
}

bool UFortItemShopVM::ShouldUseBattlePassLevelUpText() const
{
	return false;
}

void UFortItemShopVM::StartMonitoringForUpdates(const UObject* RequestingObject)
{
}

void UFortItemShopVM::StopMonitoringForUpdates(const UObject* RequestingObject)
{
}

void UFortItemShopVM::UpdateContentOrdering()
{
}
