// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortIndicatedActorManagementLibrary.h"

void UFortIndicatedActorManagementLibrary::AddActorsInRadiusToIndicatedList(AController* InstigatingController, TArray<FIndicatedActorDataWithFilter> IndicatedActorFilterDatas, const bool bAddAsUnique, const bool bReplaceExistingEntry, const bool bRefreshExistingEntry, AActor* InstigatingActorOverride)
{
}

void UFortIndicatedActorManagementLibrary::AddActorsInRadiusToStenciledList(AController* InstigatingController, TArray<FIndicatedActorDataWithFilter> StenciledActorFilterDatas, const bool bAddAsUnique, const bool bReplaceExistingEntry, const bool bRefreshExistingEntry, AActor* InstigatingActorOverride)
{
}

void UFortIndicatedActorManagementLibrary::AddActorsToIndicatedList(AController* InstigatingController, TArray<AActor*> IndicatedActors, FIndicatedActorData IndicatedActorData, const bool bAddAsUnique, const bool bAllowOwningPlayer, const bool bReplaceExistingEntry, const bool bRefreshExistingEntry)
{
}

void UFortIndicatedActorManagementLibrary::AddActorsToIndicatedListWithFilter(AController* InstigatingController, TArray<AActor*> ActorsToFilter, TArray<FIndicatedActorDataWithFilter> IndicatedActorFilterDatas, const bool bAddAsUnique, const bool bReplaceExistingEntry, const bool bRefreshExistingEntry, AActor* InstigatingActorOverride, bool bPerformRadiusCheck)
{
}

void UFortIndicatedActorManagementLibrary::AddActorsToStenciledList(AController* InstigatingController, TArray<AActor*> StenciledActors, FStenciledActorData StenciledActorData, const bool bAddAsUnique, const bool bReplaceExistingEntry, const bool bRefreshExistingEntry)
{
}

bool UFortIndicatedActorManagementLibrary::IsActorInIndicatedListForController(const AController* Controller, const AActor* ActorToCheck)
{
	return false;
}

bool UFortIndicatedActorManagementLibrary::IsActorInStenciledListForController(const AController* Controller, const AActor* ActorToCheck)
{
	return false;
}

FIndicatedActorData UFortIndicatedActorManagementLibrary::MakeIndicatedActorData(const FString& GroupIdentifier, FIndicatedActorScaleAndOpacityData ScaleAndOpacityData, FIndicatedActorParticleSystemData ParticleSystemData, FGameplayTagContainer EventTags, float Duration, float StepTime, FVector IndicatorOffset, FVector IndicatorDBNOOffset, EShareActorWith ShareActorWith, USoundBase* Sound, EIndicatorStateImage StateImageOverride, bool bClampToScreen, bool bHideStateImage, bool bOnlyDisplayWhenStencilingIsDisabled)
{
	return FIndicatedActorData();
}

FIndicatedActorDataWithFilter UFortIndicatedActorManagementLibrary::MakeIndicatedActorDataWithFilter(FGameplayTagContainer IndicateActorTags, FGameplayTagQuery IndicatedActorTagQuery, TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes, TSoftClassPtr<AActor> ActorClassFilter, TArray<TEnumAsByte<EFortTeamAffiliation::Type>>& InAffiliations, FIndicatedActorData IndicatedActorData, FStenciledActorData StenciledActorData, float OverlapRadius, float OverlapHalfHeight)
{
	return FIndicatedActorDataWithFilter();
}

FIndicatedActorParticleSystemData UFortIndicatedActorManagementLibrary::MakeIndicatedActorParticleSystemData(UParticleSystem* ParticleSystem, FName ActorParamName, FVector Offset, FVector DBNOOffset, FName VectorParamName)
{
	return FIndicatedActorParticleSystemData();
}

FIndicatedActorScaleAndOpacityData UFortIndicatedActorManagementLibrary::MakeIndicatedActorScaleAndOpacityData(float SmallSizeDistance, float LargestSizeDistance, float SmallScale, float LargestScale, float FarAwayScale, float FarAwayOpacity, float MaxScaleAndFadePercent)
{
	return FIndicatedActorScaleAndOpacityData();
}

FStenciledActorData UFortIndicatedActorManagementLibrary::MakeStenciledActorData(const FString& GroupIdentifier, FIndicatedActorParticleSystemData ParticleSystemData, float Duration, float StepTime, EShareActorWith ShareActorWith, USoundBase* Sound, FName FriendlyStencilName, FName EnemyStencilName)
{
	return FStenciledActorData();
}

void UFortIndicatedActorManagementLibrary::RemoveActorFromIndicatedList(AController* InstigatingController, AActor* IndicatedActor, const bool bIncludeSquad)
{
}

void UFortIndicatedActorManagementLibrary::RemoveActorFromStenciledList(AController* InstigatingController, AActor* StenciledActor, const bool bIncludeSquad)
{
}

void UFortIndicatedActorManagementLibrary::RemoveGroupFromIndicatedList(AController* InstigatingController, const FString& GroupIdentifier, const bool bIncludeSquad)
{
}

void UFortIndicatedActorManagementLibrary::RemoveGroupFromStenciledList(AController* InstigatingController, const FString& GroupIdentifier, const bool bIncludeSquad)
{
}
