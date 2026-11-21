// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ReticleExtensions/FortWeaponReticleRechargeStackBasePipCollectionBase.h"

UFortWeaponReticleRechargeStackBasePipCollectionBase::UFortWeaponReticleRechargeStackBasePipCollectionBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

const int32 UFortWeaponReticleRechargeStackBasePipCollectionBase::GetCurrentCount() const
{
	return int32();
}

const UDynamicEntryBox* UFortWeaponReticleRechargeStackBasePipCollectionBase::GetDynamicEntryBox() const
{
	return nullptr;
}

void UFortWeaponReticleRechargeStackBasePipCollectionBase::SetDynamicEntryBox(UDynamicEntryBox* DynamicEntryBox)
{
}

void UFortWeaponReticleRechargeStackBasePipCollectionBase::SetPipColor(const float Progress, const int32 Index, const FLinearColor NotReadyColor, const FLinearColor ReadyColor, const FName PipColorMatParamName)
{
}

void UFortWeaponReticleRechargeStackBasePipCollectionBase::UpdateRemainingRechargeTime(const float TimeRemaining, const float TotalDuration, const FName PipPercentMatParamName, const bool ShouldSetPipColor, const FLinearColor NotReadyColor, const FLinearColor ReadyColor, const FName PipColorMatParamName)
{
}

void UFortWeaponReticleRechargeStackBasePipCollectionBase::UpdateRemainingRechargeTimeAtIndex(const float FillPercent, const int32 Index, const FName PipPercentMatParamName, const bool ShouldSetPipColor, const FLinearColor NotReadyColor, const FLinearColor ReadyColor, const FName PipColorMatParamName)
{
}
