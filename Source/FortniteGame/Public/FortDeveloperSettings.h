// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Engine/DeveloperSettings.h"
#include "SocialTypes.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Online/FortPartyMember.h"
#include "FortDeveloperSettings.generated.h"

class UFortEventItemDefinitionBase;
class UFortHardcoreModifierItemDefinition;
class UFortMontageItemDefinitionBase;
class UFortQuestItemDefinition;

USTRUCT()
struct FDevFortPartyMemberRepData : public FFortPartyMemberRepData
{
	GENERATED_BODY()

};

USTRUCT()
struct FDevPartyMember
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="DevPartyMember")
	FString ContextName;

	UPROPERTY(EditAnywhere, Category="DevPartyMember")
	FString Email;

	UPROPERTY(EditAnywhere, Category="DevPartyMember")
	FString Password;

	UPROPERTY(EditAnywhere, Category="DevPartyMember")
	FFortAthenaLoadout AthenaLoadout;

	UPROPERTY(EditAnywhere, Category="DevPartyMember")
	TObjectPtr<UFortMontageItemDefinitionBase> Emote;

	UPROPERTY(EditAnywhere, Category="DevPartyMember")
	int32 SeasonLevel;

	UPROPERTY(EditAnywhere, Category="DevPartyMember")
	ECrossplayPreference CrossplayPreference;

	UPROPERTY(EditAnywhere, Category="DevPartyMember")
	FString JsonPartyMemberData;

	UPROPERTY(EditAnywhere, Category="DevPartyMember")
	FString Platform;

	UPROPERTY(EditAnywhere, Category="DevPartyMember")
	ECommonInputType InputType;

};

USTRUCT()
struct FMeshNetworkEditorSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MeshNetworkEditorSettings")
	bool bEnableMeshNetwork;

	UPROPERTY(EditAnywhere, Category="MeshNetworkEditorSettings")
	int32 BaseMeshPort;

	UPROPERTY(EditAnywhere, Category="MeshNetworkEditorSettings")
	int32 BaseMeshGamePort;

	UPROPERTY(EditAnywhere, Category="MeshNetworkEditorSettings")
	int32 NumRootClients;

	UPROPERTY(EditAnywhere, Category="MeshNetworkEditorSettings", meta=(DisplayName="Root Login Start Index"))
	int32 RootLoginStartIndex;

	UPROPERTY(EditAnywhere, Category="MeshNetworkEditorSettings")
	FString MeshMetadata;

};

UCLASS(Config=EditorPerProjectUserSettings, MinimalAPI, meta=(DisplayName="Common Developer Settings"))
class UFortDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Quests")
	TArray<TSoftObjectPtr<UFortQuestItemDefinition>> QuestItemOverrides;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Quests")
	bool bAllowAllPlayerToCountAsPartyAssist;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Quests")
	bool bAllowAllSquadMembersSharedQuests;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Athena")
	bool bForceBRCullDistances;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="HardcoreModifiers")
	TArray<TSoftObjectPtr<UFortHardcoreModifierItemDefinition>> HardcoreModifierOverrides;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Events")
	TArray<TObjectPtr<UFortEventItemDefinitionBase>> ForceActiveEvents;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="MeshNetwork", meta=(ShowOnlyInnerProperties="TRUE"))
	FMeshNetworkEditorSettings MeshNetworkSettings;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Social")
	TArray<FDevPartyMember> DevPartyMembers;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="UI")
	bool ReloadUIAfterCompilingBlueprints;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="UI")
	bool bAllowSlateGlobalInvalidationModeInPIE;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="UI")
	bool bShowSlateGlobalInvalidationDebuggingInPIE;
#endif

};

