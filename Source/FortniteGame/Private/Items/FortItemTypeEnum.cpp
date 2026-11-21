// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortItemTypeEnum.h"
#include "Containers/StaticBitArray.h"

FName EFortItemType_ToName(EFortItemType ItemType)
{
	switch (ItemType)
	{
	case EFortItemType::WorldItem:
	{
		static const FName PrimaryAssetType(TEXT("WorldItem"));
		return PrimaryAssetType;
	}
	case EFortItemType::Ammo:
	{
		static const FName PrimaryAssetType(TEXT("Ammo"));
		return PrimaryAssetType;
	}
	case EFortItemType::Badge:
	{
		static const FName PrimaryAssetType(TEXT("Badge"));
		return PrimaryAssetType;
	}
	case EFortItemType::BackpackPickup:
	{
		static const FName PrimaryAssetType(TEXT("BackpackPickup"));
		return PrimaryAssetType;
	}
	case EFortItemType::BuildingPiece:
	{
		static const FName PrimaryAssetType(TEXT("BuildingPiece"));
		return PrimaryAssetType;
	}
	case EFortItemType::CharacterPart:
	{
		static const FName PrimaryAssetType(TEXT("CharacterPart"));
		return PrimaryAssetType;
	}
	case EFortItemType::Consumable:
	{
		static const FName PrimaryAssetType(TEXT("Consumable"));
		return PrimaryAssetType;
	}
	case EFortItemType::Deco:
	{
		static const FName PrimaryAssetType(TEXT("Deco"));
		return PrimaryAssetType;
	}
	case EFortItemType::EditTool:
	{
		static const FName PrimaryAssetType(TEXT("EditTool"));
		return PrimaryAssetType;
	}
	case EFortItemType::Ingredient:
	{
		static const FName PrimaryAssetType(TEXT("Ingredient"));
		return PrimaryAssetType;
	}
	case EFortItemType::ItemCache:
	{
		static const FName PrimaryAssetType(TEXT("ItemCache"));
		return PrimaryAssetType;
	}
	case EFortItemType::Food:
	{
		static const FName PrimaryAssetType(TEXT("Food"));
		return PrimaryAssetType;
	}
	case EFortItemType::Gadget:
	{
		static const FName PrimaryAssetType(TEXT("Gadget"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaGadget:
	{
		static const FName PrimaryAssetType(TEXT("AthenaGadget"));
		return PrimaryAssetType;
	}
	case EFortItemType::HomebaseGadget:
	{
		static const FName PrimaryAssetType(TEXT("HomebaseGadget"));
		return PrimaryAssetType;
	}
	case EFortItemType::BattleLabDevice:
	{
		static const FName PrimaryAssetType(TEXT("BattleLabDevice"));
		return PrimaryAssetType;
	}
	case EFortItemType::SpyTechPerk:
	{
		static const FName PrimaryAssetType(TEXT("SpyTechPerk"));
		return PrimaryAssetType;
	}
	case EFortItemType::HeroAbility:
	{
		static const FName PrimaryAssetType(TEXT("HeroAbility"));
		return PrimaryAssetType;
	}
	case EFortItemType::MissionItem:
	{
		static const FName PrimaryAssetType(TEXT("MissionItem"));
		return PrimaryAssetType;
	}
	case EFortItemType::Trap:
	{
		static const FName PrimaryAssetType(TEXT("Trap"));
		return PrimaryAssetType;
	}
	case EFortItemType::MultiItem:
	{
		static const FName PrimaryAssetType(TEXT("MultiItem"));
		return PrimaryAssetType;
	}
	case EFortItemType::Weapon:
	{
		static const FName PrimaryAssetType(TEXT("Weapon"));
		return PrimaryAssetType;
	}
	case EFortItemType::WeaponMelee:
	{
		static const FName PrimaryAssetType(TEXT("WeaponMelee"));
		return PrimaryAssetType;
	}
	case EFortItemType::WeaponRanged:
	{
		static const FName PrimaryAssetType(TEXT("WeaponRanged"));
		return PrimaryAssetType;
	}
	case EFortItemType::WeaponHarvest:
	{
		static const FName PrimaryAssetType(TEXT("WeaponHarvest"));
		return PrimaryAssetType;
	}
	case EFortItemType::WeaponCreativePhone:
	{
		static const FName PrimaryAssetType(TEXT("WeaponCreativePhone"));
		return PrimaryAssetType;
	}
	case EFortItemType::WeaponMod:
	{
		static const FName PrimaryAssetType(TEXT("WeaponMod"));
		return PrimaryAssetType;
	}
	case EFortItemType::WorldResource:
	{
		static const FName PrimaryAssetType(TEXT("WorldResource"));
		return PrimaryAssetType;
	}
	case EFortItemType::CreativeUserPrefab:
	{
		static const FName PrimaryAssetType(TEXT("CreativeUserPrefab"));
		return PrimaryAssetType;
	}
	case EFortItemType::CreativePlayset:
	{
		static const FName PrimaryAssetType(TEXT("CreativePlayset"));
		return PrimaryAssetType;
	}
	case EFortItemType::Vehicle:
	{
		static const FName PrimaryAssetType(TEXT("Vehicle"));
		return PrimaryAssetType;
	}
	case EFortItemType::PlayerAugment:
	{
		static const FName PrimaryAssetType(TEXT("PlayerAugment"));
		return PrimaryAssetType;
	}
	case EFortItemType::AccountItem:
	{
		static const FName PrimaryAssetType(TEXT("AccountItem"));
		return PrimaryAssetType;
	}
	case EFortItemType::AccountResource:
	{
		static const FName PrimaryAssetType(TEXT("AccountResource"));
		return PrimaryAssetType;
	}
	case EFortItemType::CollectedResource:
	{
		static const FName PrimaryAssetType(TEXT("CollectedResource"));
		return PrimaryAssetType;
	}
	case EFortItemType::Alteration:
	{
		static const FName PrimaryAssetType(TEXT("Alteration"));
		return PrimaryAssetType;
	}
	case EFortItemType::CardPack:
	{
		static const FName PrimaryAssetType(TEXT("CardPack"));
		return PrimaryAssetType;
	}
	case EFortItemType::Currency:
	{
		static const FName PrimaryAssetType(TEXT("Currency"));
		return PrimaryAssetType;
	}
	case EFortItemType::Hero:
	{
		static const FName PrimaryAssetType(TEXT("Hero"));
		return PrimaryAssetType;
	}
	case EFortItemType::Schematic:
	{
		static const FName PrimaryAssetType(TEXT("Schematic"));
		return PrimaryAssetType;
	}
	case EFortItemType::Worker:
	{
		static const FName PrimaryAssetType(TEXT("Worker"));
		return PrimaryAssetType;
	}
	case EFortItemType::TeamPerk:
	{
		static const FName PrimaryAssetType(TEXT("TeamPerk"));
		return PrimaryAssetType;
	}
	case EFortItemType::PlayerTech:
	{
		static const FName PrimaryAssetType(TEXT("PlayerTech"));
		return PrimaryAssetType;
	}
	case EFortItemType::Token:
	{
		static const FName PrimaryAssetType(TEXT("Token"));
		return PrimaryAssetType;
	}
	case EFortItemType::DailyRewardScheduleToken:
	{
		static const FName PrimaryAssetType(TEXT("DailyRewardScheduleToken"));
		return PrimaryAssetType;
	}
	case EFortItemType::CodeToken:
	{
		static const FName PrimaryAssetType(TEXT("CodeToken"));
		return PrimaryAssetType;
	}
	case EFortItemType::Stat:
	{
		static const FName PrimaryAssetType(TEXT("Stat"));
		return PrimaryAssetType;
	}
	case EFortItemType::Buff:
	{
		static const FName PrimaryAssetType(TEXT("Buff"));
		return PrimaryAssetType;
	}
	case EFortItemType::BuffCredit:
	{
		static const FName PrimaryAssetType(TEXT("BuffCredit"));
		return PrimaryAssetType;
	}
	case EFortItemType::Quest:
	{
		static const FName PrimaryAssetType(TEXT("Quest"));
		return PrimaryAssetType;
	}
	case EFortItemType::Accolades:
	{
		static const FName PrimaryAssetType(TEXT("Accolades"));
		return PrimaryAssetType;
	}
	case EFortItemType::FriendChest:
	{
		static const FName PrimaryAssetType(TEXT("FriendChest"));
		return PrimaryAssetType;
	}
	case EFortItemType::MedalsPunchCard:
	{
		static const FName PrimaryAssetType(TEXT("MedalsPunchCard"));
		return PrimaryAssetType;
	}
	case EFortItemType::RepeatableDailiesCard:
	{
		static const FName PrimaryAssetType(TEXT("RepeatableDailiesCard"));
		return PrimaryAssetType;
	}
	case EFortItemType::ChallengeBundle:
	{
		static const FName PrimaryAssetType(TEXT("ChallengeBundle"));
		return PrimaryAssetType;
	}
	case EFortItemType::ChallengeBundleSchedule:
	{
		static const FName PrimaryAssetType(TEXT("ChallengeBundleSchedule"));
		return PrimaryAssetType;
	}
	case EFortItemType::ChallengeBundleCompletionToken:
	{
		static const FName PrimaryAssetType(TEXT("ChallengeBundleCompletionToken"));
		return PrimaryAssetType;
	}
	case EFortItemType::GameplayModifier:
	{
		static const FName PrimaryAssetType(TEXT("GameplayModifier"));
		return PrimaryAssetType;
	}
	case EFortItemType::Outpost:
	{
		static const FName PrimaryAssetType(TEXT("Outpost"));
		return PrimaryAssetType;
	}
	case EFortItemType::HomebaseNode:
	{
		static const FName PrimaryAssetType(TEXT("HomebaseNode"));
		return PrimaryAssetType;
	}
	case EFortItemType::Defender:
	{
		static const FName PrimaryAssetType(TEXT("Defender"));
		return PrimaryAssetType;
	}
	case EFortItemType::ConversionControl:
	{
		static const FName PrimaryAssetType(TEXT("ConversionControl"));
		return PrimaryAssetType;
	}
	case EFortItemType::DeployableBaseCloudSave:
	{
		static const FName PrimaryAssetType(TEXT("DeployableBaseCloudSave"));
		return PrimaryAssetType;
	}
	case EFortItemType::ConsumableAccountItem:
	{
		static const FName PrimaryAssetType(TEXT("ConsumableAccountItem"));
		return PrimaryAssetType;
	}
	case EFortItemType::Quota:
	{
		static const FName PrimaryAssetType(TEXT("Quota"));
		return PrimaryAssetType;
	}
	case EFortItemType::Expedition:
	{
		static const FName PrimaryAssetType(TEXT("Expedition"));
		return PrimaryAssetType;
	}
	case EFortItemType::HomebaseBannerIcon:
	{
		static const FName PrimaryAssetType(TEXT("HomebaseBannerIcon"));
		return PrimaryAssetType;
	}
	case EFortItemType::HomebaseBannerColor:
	{
		static const FName PrimaryAssetType(TEXT("HomebaseBannerColor"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaSkyDiveContrail:
	{
		static const FName PrimaryAssetType(TEXT("AthenaSkyDiveContrail"));
		return PrimaryAssetType;
	}
	case EFortItemType::PersonalVehicle:
	{
		static const FName PrimaryAssetType(TEXT("PersonalVehicle"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaGlider:
	{
		static const FName PrimaryAssetType(TEXT("AthenaGlider"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaPickaxe:
	{
		static const FName PrimaryAssetType(TEXT("AthenaPickaxe"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaHat:
	{
		static const FName PrimaryAssetType(TEXT("AthenaHat"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaBackpack:
	{
		static const FName PrimaryAssetType(TEXT("AthenaBackpack"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaCharacter:
	{
		static const FName PrimaryAssetType(TEXT("AthenaCharacter"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaDance:
	{
		static const FName PrimaryAssetType(TEXT("AthenaDance"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaConsumableEmote:
	{
		static const FName PrimaryAssetType(TEXT("AthenaConsumableEmote"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaLoadingScreen:
	{
		static const FName PrimaryAssetType(TEXT("AthenaLoadingScreen"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaBattleBus:
	{
		static const FName PrimaryAssetType(TEXT("AthenaBattleBus"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaVehicleCosmetic:
	{
		static const FName PrimaryAssetType(TEXT("AthenaVehicleCosmetic"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaItemWrap:
	{
		static const FName PrimaryAssetType(TEXT("AthenaItemWrap"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaCallingCard:
	{
		static const FName PrimaryAssetType(TEXT("AthenaCallingCard"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaMapMarker:
	{
		static const FName PrimaryAssetType(TEXT("AthenaMapMarker"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaMusicPack:
	{
		static const FName PrimaryAssetType(TEXT("AthenaMusicPack"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaPetCosmetic:
	{
		static const FName PrimaryAssetType(TEXT("AthenaPetCosmetic"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaCharmCosmetic:
	{
		static const FName PrimaryAssetType(TEXT("AthenaCharmCosmetic"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaVictoryPose:
	{
		static const FName PrimaryAssetType(TEXT("AthenaVictoryPose"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaSeasonTreasure:
	{
		static const FName PrimaryAssetType(TEXT("AthenaSeasonTreasure"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaSeason:
	{
		static const FName PrimaryAssetType(TEXT("AthenaSeason"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaRewardGraph:
	{
		static const FName PrimaryAssetType(TEXT("AthenaRewardGraph"));
		return PrimaryAssetType;
	}
	case EFortItemType::AthenaExtResource:
	{
		static const FName PrimaryAssetType(TEXT("AthenaExtResource"));
		return PrimaryAssetType;
	}
	case EFortItemType::EventDescription:
	{
		static const FName PrimaryAssetType(TEXT("EventDescription"));
		return PrimaryAssetType;
	}
	case EFortItemType::BattleLabDeviceAccount:
	{
		static const FName PrimaryAssetType(TEXT("BattleLabDeviceAccount"));
		return PrimaryAssetType;
	}
	case EFortItemType::EventPurchaseTracker:
	{
		static const FName PrimaryAssetType(TEXT("EventPurchaseTracker"));
		return PrimaryAssetType;
	}
	case EFortItemType::CosmeticVariantToken:
	{
		static const FName PrimaryAssetType(TEXT("CosmeticVariantToken"));
		return PrimaryAssetType;
	}
	case EFortItemType::CampaignHeroLoadout:
	{
		static const FName PrimaryAssetType(TEXT("CampaignHeroLoadout"));
		return PrimaryAssetType;
	}
	case EFortItemType::Playset:
	{
		static const FName PrimaryAssetType(TEXT("Playset"));
		return PrimaryAssetType;
	}
	case EFortItemType::PrerollData:
	{
		static const FName PrimaryAssetType(TEXT("PrerollData"));
		return PrimaryAssetType;
	}
	case EFortItemType::CreativePlot:
	{
		static const FName PrimaryAssetType(TEXT("CreativePlot"));
		return PrimaryAssetType;
	}
	case EFortItemType::PlayerSurveyToken:
	{
		static const FName PrimaryAssetType(TEXT("PlayerSurveyToken"));
		return PrimaryAssetType;
	}
	case EFortItemType::CosmeticLocker:
	{
		static const FName PrimaryAssetType(TEXT("CosmeticLocker"));
		return PrimaryAssetType;
	}
	case EFortItemType::BannerToken:
	{
		static const FName PrimaryAssetType(TEXT("BannerToken"));
		return PrimaryAssetType;
	}
	case EFortItemType::RestedXpBoosterToken:
	{
		static const FName PrimaryAssetType(TEXT("RestedXpBoosterToken"));
		return PrimaryAssetType;
	}
	case EFortItemType::RewardEventGraphPurchaseToken:
	{
		static const FName PrimaryAssetType(TEXT("RewardEventGraphPurchaseToken"));
		return PrimaryAssetType;
	}
	case EFortItemType::HardcoreModifier:
	{
		static const FName PrimaryAssetType(TEXT("HardcoreModifier"));
		return PrimaryAssetType;
	}
	case EFortItemType::EventDependentItem:
	{
		static const FName PrimaryAssetType(TEXT("EventDependentItem"));
		return PrimaryAssetType;
	}
	case EFortItemType::ItemAccessToken:
	{
		static const FName PrimaryAssetType(TEXT("ItemAccessToken"));
		return PrimaryAssetType;
	}
	case EFortItemType::STWAccoladeReward:
	{
		static const FName PrimaryAssetType(TEXT("STWAccoladeReward"));
		return PrimaryAssetType;
	}
	case EFortItemType::Campsite:
	{
		static const FName PrimaryAssetType(TEXT("Campsite"));
		return PrimaryAssetType;
	}
	case EFortItemType::VictoryCrown:
	{
		static const FName PrimaryAssetType(TEXT("VictoryCrown"));
		return PrimaryAssetType;
	}
	case EFortItemType::RealitySapling:
	{
		static const FName PrimaryAssetType(TEXT("RealitySapling"));
		return PrimaryAssetType;
	}
	case EFortItemType::Apparel:
	{
		static const FName PrimaryAssetType(TEXT("Apparel"));
		return PrimaryAssetType;
	}
	case EFortItemType::ApparelLayout:
	{
		static const FName PrimaryAssetType(TEXT("ApparelLayout"));
		return PrimaryAssetType;
	}
	case EFortItemType::PlayerAugmentsPersistence:
	{
		static const FName PrimaryAssetType(TEXT("PlayerAugmentsPersistence"));
		return PrimaryAssetType;
	}
	case EFortItemType::SparksCosmeticItem:
	{
		static const FName PrimaryAssetType(TEXT("SparksCosmeticItem"));
		return PrimaryAssetType;
	}
	case EFortItemType::SpecialItem:
	{
		static const FName PrimaryAssetType(TEXT("SpecialItem"));
		return PrimaryAssetType;
	}
	case EFortItemType::Emote:
	{
		static const FName PrimaryAssetType(TEXT("Emote"));
		return PrimaryAssetType;
	}
	case EFortItemType::Stack:
	{
		static const FName PrimaryAssetType(TEXT("Stack"));
		return PrimaryAssetType;
	}
	case EFortItemType::CollectionBookPage:
	{
		static const FName PrimaryAssetType(TEXT("CollectionBookPage"));
		return PrimaryAssetType;
	}
	case EFortItemType::BGAConsumableWrapper:
	{
		static const FName PrimaryAssetType(TEXT("BGAConsumableWrapper"));
		return PrimaryAssetType;
	}
	case EFortItemType::GiftBox:
	{
		static const FName PrimaryAssetType(TEXT("GiftBox"));
		return PrimaryAssetType;
	}
	case EFortItemType::GiftBoxUnlock:
	{
		static const FName PrimaryAssetType(TEXT("GiftBoxUnlock"));
		return PrimaryAssetType;
	}
	case EFortItemType::PlaysetProp:
	{
		static const FName PrimaryAssetType(TEXT("PlaysetProp"));
		return PrimaryAssetType;
	}
	case EFortItemType::Profile:
	{
		static const FName PrimaryAssetType(TEXT("Profile"));
		return PrimaryAssetType;
	}
	default:
	{
		static TStaticBitArray<256> ReportedItemTypes;
		const int32 ItemTypeIndex = (int32)ItemType;
		if (!ReportedItemTypes[ItemTypeIndex])
		{
			ReportedItemTypes[ItemTypeIndex] = true;
			ensureAlwaysMsgf(false, TEXT("%hs: Unhandled EFortItemType (%s)."), __FUNCTION__, *UEnum::GetValueAsName(ItemType).ToString());
		}

		return NAME_None;
	}
	}
}

EFortItemType UFortItemTypeFunctionLibrary::GetTemplateType(EFortItemType ItemType)
{
	switch (ItemType)
	{
	case EFortItemType::Badge:
	case EFortItemType::BackpackPickup:
	case EFortItemType::ItemCache:
	case EFortItemType::MissionItem:
	case EFortItemType::WorldResource:
		return EFortItemType::WorldItem;

	case EFortItemType::BuildingPiece:
	case EFortItemType::EditTool:
	case EFortItemType::WeaponMelee:
	case EFortItemType::WeaponRanged:
	case EFortItemType::WeaponHarvest:
	case EFortItemType::WeaponCreativePhone:
		return EFortItemType::Weapon;

	case EFortItemType::HomebaseGadget:
	case EFortItemType::HeroAbility:
		return EFortItemType::Gadget;

	case EFortItemType::Stack:
		return EFortItemType::Max_None;

	default:
		return ItemType;
	}
}

FText UFortItemTypeFunctionLibrary::ToText(EFortItemType ItemType, bool UsePlural)
{
	return FText();
}
