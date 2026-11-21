// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Components/FortControllerComponent_IndicatedActorManagement.h"
#include "FortTeamEnum.h"
#include "FortIndicatedActorManagementLibrary.generated.h"

class AActor;
class AController;
class UParticleSystem;
class USoundBase;
enum class EIndicatorStateImage : uint8;
enum class EShareActorWith : uint8;

UCLASS(meta=(ScriptName="FortIndicatedActorManagementLibrary"))
class UFortIndicatedActorManagementLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Indicated Management", meta=(DisplayName="Add Actors In Radius To Indicated List"))
	static void AddActorsInRadiusToIndicatedList(AController* InstigatingController, TArray<FIndicatedActorDataWithFilter> IndicatedActorFilterDatas, const bool bAddAsUnique = false, const bool bReplaceExistingEntry = false, const bool bRefreshExistingEntry = false, AActor* InstigatingActorOverride = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Indicated Management", meta=(DisplayName="Add Actors In Radius To Stenciled List"))
	static void AddActorsInRadiusToStenciledList(AController* InstigatingController, TArray<FIndicatedActorDataWithFilter> StenciledActorFilterDatas, const bool bAddAsUnique = false, const bool bReplaceExistingEntry = false, const bool bRefreshExistingEntry = false, AActor* InstigatingActorOverride = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Indicated Management", meta=(DisplayName="Add Actors To Indicated List"))
	static void AddActorsToIndicatedList(AController* InstigatingController, TArray<AActor*> IndicatedActors, FIndicatedActorData IndicatedActorData, const bool bAddAsUnique = false, const bool bAllowOwningPlayer = false, const bool bReplaceExistingEntry = false, const bool bRefreshExistingEntry = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Indicated Management", meta=(DisplayName="Add Actors To Indicated List With Filter"))
	static void AddActorsToIndicatedListWithFilter(AController* InstigatingController, TArray<AActor*> ActorsToFilter, TArray<FIndicatedActorDataWithFilter> IndicatedActorFilterDatas, const bool bAddAsUnique = false, const bool bReplaceExistingEntry = false, const bool bRefreshExistingEntry = false, AActor* InstigatingActorOverride = nullptr, bool bPerformRadiusCheck = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Indicated Management", meta=(DisplayName="Add Actors To Stenciled List"))
	static void AddActorsToStenciledList(AController* InstigatingController, TArray<AActor*> StenciledActors, FStenciledActorData StenciledActorData, const bool bAddAsUnique = false, const bool bReplaceExistingEntry = false, const bool bRefreshExistingEntry = false);

	UFUNCTION(BlueprintPure, Category="Indicated Management")
	static bool IsActorInIndicatedListForController(const AController* Controller, const AActor* ActorToCheck);

	UFUNCTION(BlueprintPure, Category="Indicated Management")
	static bool IsActorInStenciledListForController(const AController* Controller, const AActor* ActorToCheck);

	UFUNCTION(BlueprintPure, Category="Indicated Management")
	static FIndicatedActorData MakeIndicatedActorData(const FString& GroupIdentifier, FIndicatedActorScaleAndOpacityData ScaleAndOpacityData, FIndicatedActorParticleSystemData ParticleSystemData, FGameplayTagContainer EventTags, float Duration = 15.000000f, float StepTime = 0.100000f, FVector IndicatorOffset = FVector(0.000000, 0.000000, 90.000000), FVector IndicatorDBNOOffset = FVector(0.000000, 0.000000, 30.000000), EShareActorWith ShareActorWith = EShareActorWith::None, USoundBase* Sound = nullptr, EIndicatorStateImage StateImageOverride = EIndicatorStateImage::None, bool bClampToScreen = false, bool bHideStateImage = false, bool bOnlyDisplayWhenStencilingIsDisabled = false);

	UFUNCTION(BlueprintPure, Category="Indicated Management", meta=(AutoCreateRefTerm="InAffiliations"))
	static FIndicatedActorDataWithFilter MakeIndicatedActorDataWithFilter(FGameplayTagContainer IndicateActorTags, FGameplayTagQuery IndicatedActorTagQuery, TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes, TSoftClassPtr<AActor> ActorClassFilter, TArray<TEnumAsByte<EFortTeamAffiliation::Type>>& InAffiliations, FIndicatedActorData IndicatedActorData, FStenciledActorData StenciledActorData, float OverlapRadius = 2048.000000f, float OverlapHalfHeight = 0.000000f);

	UFUNCTION(BlueprintPure, Category="Indicated Management", meta=(CPP_Default_ActorParamName, CPP_Default_Offset, CPP_Default_DBNOOffset))
	static FIndicatedActorParticleSystemData MakeIndicatedActorParticleSystemData(UParticleSystem* ParticleSystem, FName ActorParamName, FVector Offset, FVector DBNOOffset, FName VectorParamName = FName(TEXT("")));

	UFUNCTION(BlueprintPure, Category="Indicated Management")
	static FIndicatedActorScaleAndOpacityData MakeIndicatedActorScaleAndOpacityData(float SmallSizeDistance = 7500.000000f, float LargestSizeDistance = 10.000000f, float SmallScale = 0.500000f, float LargestScale = 0.800000f, float FarAwayScale = 0.350000f, float FarAwayOpacity = 1.000000f, float MaxScaleAndFadePercent = 0.100000f);

	UFUNCTION(BlueprintPure, Category="Indicated Management")
	static FStenciledActorData MakeStenciledActorData(const FString& GroupIdentifier, FIndicatedActorParticleSystemData ParticleSystemData, float Duration = 15.000000f, float StepTime = 0.100000f, EShareActorWith ShareActorWith = EShareActorWith::None, USoundBase* Sound = nullptr, FName FriendlyStencilName = NAME_None, FName EnemyStencilName = NAME_None);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Indicated Management", meta=(DisplayName="Remove Actor From Indicated List"))
	static void RemoveActorFromIndicatedList(AController* InstigatingController, AActor* IndicatedActor, const bool bIncludeSquad = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Indicated Management", meta=(DisplayName="Remove Actor From Stenciled List"))
	static void RemoveActorFromStenciledList(AController* InstigatingController, AActor* StenciledActor, const bool bIncludeSquad = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Indicated Management", meta=(DisplayName="Remove Group From Indicated List"))
	static void RemoveGroupFromIndicatedList(AController* InstigatingController, const FString& GroupIdentifier, const bool bIncludeSquad = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Indicated Management", meta=(DisplayName="Remove Group From Stenciled List"))
	static void RemoveGroupFromStenciledList(AController* InstigatingController, const FString& GroupIdentifier, const bool bIncludeSquad = true);

};

